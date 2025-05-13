/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdio.h>
#include "app.h"
#include "definitions.h"

//#define LOG_FPS_CALCULATION

#define MAX_LUMA_WIDTH   800
#define MAX_CHROMA_WIDTH 400

#define XPHIDEF 0
#define YPHIDEF 0

#define SDCARD_MOUNT_NAME    SYS_FS_MEDIA_IDX0_MOUNT_NAME_VOLUME_IDX0
#define JPEG_FILE_NUM        240
#define JPEG_FILE_MAX_SIZE   33000
#define START_PIC_NUM        145
#define END_PIC_NUM          (START_PIC_NUM + JPEG_FILE_NUM - 1)

typedef struct
{
    uint32_t addr;
    uint32_t ctrl;
    uint32_t next;
    uint32_t reserved;
} dma_desc;

dma_desc __attribute__ ((section(".region_nocache"), aligned (64))) desc_y[2];
dma_desc __attribute__ ((section(".region_nocache"), aligned (64))) desc_u[2];
dma_desc __attribute__ ((section(".region_nocache"), aligned (64))) desc_v[2];

unsigned char __attribute__ ((section(".region_nocache"), aligned (64))) buf_y[2][MAX_LUMA_WIDTH * MAX_LUMA_WIDTH];
unsigned char __attribute__ ((section(".region_nocache"), aligned (64))) buf_u[2][MAX_CHROMA_WIDTH * MAX_CHROMA_WIDTH];
unsigned char __attribute__ ((section(".region_nocache"), aligned (64))) buf_v[2][MAX_CHROMA_WIDTH * MAX_CHROMA_WIDTH];

static uint8_t pingpong = 0;

#ifdef LOG_FPS_CALCULATION
static int index = 0;
#endif

typedef struct
{
    uint8_t jpg_buf[JPEG_FILE_MAX_SIZE];
    uint32_t jpg_len;
} pic_desc;


static uint32_t heo_upscaling_xcoef[] = {
        0xf74949f7,
        0x00000000,
        0xf55f33fb,
        0x000000fe,
        0xf5701efe,
        0x000000ff,
        0xf87c0dff,
        0x00000000,
        0x00800000,
        0x00000000,
        0x0d7cf800,
        0x000000ff,
        0x1e70f5ff,
        0x000000fe,
        0x335ff5fe,
        0x000000fb,
};

static uint32_t heo_upscaling_ycoef[] = {
        0x00004040,
        0x00075920,
        0x00056f0c,
        0x00027b03,
        0x00008000,
        0x00037b02,
        0x000c6f05,
        0x00205907,
};

void HEO_Initialize(void);
extern int djpeg (char *p_jpg, int jpg_len, char *p_y, char *p_u, char *p_v, int *p_width, int *p_height);

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;
static pic_desc pics;
static uint32_t jpg_index = START_PIC_NUM;
static uint8_t jpg_file_name[10];
uint8_t firstjpg[JPEG_FILE_MAX_SIZE];

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

static void APP_SysFSEventHandler(SYS_FS_EVENT event,void* eventData,uintptr_t context)
{
    switch(event)
    {
        /* If the event is mount then check if SDCARD media has been mounted */
        case SYS_FS_EVENT_MOUNT:
            if(strcmp((const char *)eventData, SDCARD_MOUNT_NAME) == 0)
            {
                appData.sdCardMountFlag = true;
                printf("sdCard Mounted\r\n");
            }
            break;

        /* If the event is unmount then check if SDCARD media has been unmount */
        case SYS_FS_EVENT_UNMOUNT:
            if(strcmp((const char *)eventData, SDCARD_MOUNT_NAME) == 0)
            {
                appData.sdCardMountFlag = false;

                appData.state = APP_MOUNT_WAIT;

            }

            break;

        case SYS_FS_EVENT_ERROR:
        default:
            break;
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_MOUNT_WAIT;

    HEO_Initialize();

    SYS_FS_EventHandlerSet((void const*)APP_SysFSEventHandler,(uintptr_t)NULL);
    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
    printf("APP_Initialize done, heap size: 28000\r\n");
}

static void set_phicoeff(uint32_t reg_base, const uint32_t *coeff_tab, uint32_t size)
{
        uint32_t i;

        for (i = 0; i < size; i++)
                *(volatile unsigned int *)(reg_base + (i * 4)) = coeff_tab[i];
}

static void layerHEOGetScalingFactors(uint16_t xmemsize,
                                     uint16_t ymemsize,
                                     uint16_t xsize,
                                     uint16_t ysize,
                                     uint16_t* xfactor,
                                     uint16_t* yfactor)
{
    uint16_t xfactor1st, yfactor1st;

    xmemsize--;
    ymemsize--;
    xsize--;
    ysize--;

    xfactor1st = ((2048 * xmemsize - 256 * XPHIDEF)/ xsize) + 1;
    yfactor1st = ((2048 * ymemsize - 256 * XPHIDEF)/ ysize) + 1;

    if ((xfactor1st * xsize / 2048) > xmemsize)
        *xfactor = xfactor1st - 1;
    else
        *xfactor = xfactor1st;

    if ((yfactor1st * ysize / 2048) > ymemsize)
        *yfactor = yfactor1st - 1;
    else
        *yfactor = yfactor1st;
}

void update_desc(uint8_t id)
{
#ifdef LOG_FPS_CALCULATION
    static bool is_logging = true;
    if (index == 0 && is_logging) {
        printf(".\r\n");
    }
    if (index == 239 && is_logging) {
        printf("..\r\n");
        is_logging = false;
    }  
#endif
#if 1
    desc_y[0].addr = &buf_y[id];
    desc_u[0].addr = &buf_u[id];
    desc_v[0].addr = &buf_v[id];
#else
    LCDC_REGS->LCDC_HEOHEAD = &buf_y[id];
    //LCDC_REGS->LCDC_HEOCTRL = LCDC_HEOCTRL_DFETCH(1);
    //LCDC_REGS->LCDC_HEONEXT = &desc_y[id];

    LCDC_REGS->LCDC_HEOUHEAD = &buf_u[id];
    //LCDC_REGS->LCDC_HEOUCTRL = LCDC_HEOCTRL_DFETCH(1);
    //LCDC_REGS->LCDC_HEOUNEXT = &desc_u[id];

    LCDC_REGS->LCDC_HEOVHEAD = &buf_v[id];
    //LCDC_REGS->LCDC_HEOVCTRL = LCDC_HEOCTRL_DFETCH(1);
    //LCDC_REGS->LCDC_HEOVNEXT = &desc_v[id];

    LCDC_REGS->LCDC_HEOCHER = LCDC_HEOCHER_A2QEN(1);
#endif
}

void HEO_Initialize(void)
{
    uint16_t xfactor, yfactor;

    //printf("haha %s called\n\r", __func__);
    LCDC_REGS->LCDC_LCDCFG0 |= LCDC_LCDCFG0_CGDISHEO(1);

    LCDC_REGS->LCDC_HEOCFG0 = LCDC_HEOCFG0_ROTDIS(1);
    LCDC_REGS->LCDC_HEOCFG1 = LCDC_HEOCFG1_YUVEN(1) | LCDC_HEOCFG1_YUVMODE(8);
    //LCDC_REGS->LCDC_HEOCFG1 = LCDC_HEOCFG1_RGBMODE(13);
    LCDC_REGS->LCDC_HEOCFG2 = LCDC_HEOCFG2_XPOS(0) | LCDC_HEOCFG2_YPOS(61);
    //LCDC_REGS->LCDC_HEOCFG3 = LCDC_HEOCFG3_XSIZE(800 - 1) | LCDC_HEOCFG3_YSIZE(360 - 1);
    LCDC_REGS->LCDC_HEOCFG3 = LCDC_HEOCFG3_XSIZE(800 - 1) | LCDC_HEOCFG3_YSIZE(360 - 1);
    LCDC_REGS->LCDC_HEOCFG4 = LCDC_HEOCFG4_XMEMSIZE(600 - 1) | LCDC_HEOCFG4_YMEMSIZE(270 - 1);
    LCDC_REGS->LCDC_HEOCFG5 = LCDC_HEOCFG5_XSTRIDE(0);
    LCDC_REGS->LCDC_HEOCFG6 = LCDC_HEOCFG6_PSTRIDE(0);
    LCDC_REGS->LCDC_HEOCFG9 = LCDC_HEOCFG9_BDEF(0xFF) | LCDC_HEOCFG9_GDEF(0x00) | LCDC_HEOCFG9_RDEF(0x00);
    //LCDC_REGS->LCDC_HEOCFG10 = 0xFFFFFF;
    //LCDC_REGS->LCDC_HEOCFG11 = 0xFFFFFF;
    LCDC_REGS->LCDC_HEOCFG14 = 0x4c900091;
    LCDC_REGS->LCDC_HEOCFG15 = 0x7a5f5090;
    LCDC_REGS->LCDC_HEOCFG16 = 0x40040890;
    //LCDC_REGS->LCDC_HEOCFG12 = LCDC_HEOCFG12_GA(0x80) | LCDC_HEOCFG12_VIDPRI(1) | LCDC_HEOCFG12_GAEN(1);
    //LCDC_REGS->LCDC_HEOCFG12 = LCDC_HEOCFG12_GA(0x80) | LCDC_HEOCFG12_DMA(1) | LCDC_HEOCFG12_OVR(1) | LCDC_HEOCFG12_GAEN(1);
    layerHEOGetScalingFactors(600, 270, 800, 360, &xfactor, &yfactor);
    LCDC_REGS->LCDC_HEOCFG13 = LCDC_HEOCFG13_SCALEN(1) | LCDC_HEOCFG13_YFACTOR(yfactor) | LCDC_HEOCFG13_XFACTOR(xfactor);
    set_phicoeff(&LCDC_REGS->LCDC_HEOCFG17, heo_upscaling_xcoef, sizeof(heo_upscaling_xcoef) / sizeof(uint32_t));
    set_phicoeff(&LCDC_REGS->LCDC_HEOCFG33, heo_upscaling_ycoef, sizeof(heo_upscaling_ycoef) / sizeof(uint32_t));

#if 1
    desc_y[0].addr = &buf_y[0];
    desc_y[0].ctrl = LCDC_HEOCTRL_DFETCH(1);
    desc_y[0].next = (uint32_t)&desc_y[0];
    desc_y[1].addr = &buf_y[1];
    desc_y[1].ctrl = LCDC_HEOCTRL_DFETCH(1);
    desc_y[1].next = (uint32_t)&desc_y[1];
    LCDC_REGS->LCDC_HEOADDR = &buf_y[0];
    LCDC_REGS->LCDC_HEOCTRL = LCDC_HEOCTRL_DFETCH(1);
    LCDC_REGS->LCDC_HEONEXT = &desc_y[0];

    desc_u[0].addr = &buf_u[0];
    desc_u[0].ctrl = LCDC_HEOCTRL_DFETCH(1);
    desc_u[0].next = (uint32_t)&desc_u[0];
    desc_u[1].addr = &buf_u[1];
    desc_u[1].ctrl = LCDC_HEOCTRL_DFETCH(1);
    desc_u[1].next = (uint32_t)&desc_u[1];
    LCDC_REGS->LCDC_HEOUADDR = &buf_u[0];
    LCDC_REGS->LCDC_HEOUCTRL = LCDC_HEOCTRL_DFETCH(1);
    LCDC_REGS->LCDC_HEOUNEXT = &desc_u[0];

    desc_v[0].addr = &buf_v[0];
    desc_v[0].ctrl = LCDC_HEOCTRL_DFETCH(1);
    desc_v[0].next = (uint32_t)&desc_v[0];
    desc_v[1].addr = &buf_v[1];
    desc_v[1].ctrl = LCDC_HEOCTRL_DFETCH(1);
    desc_v[1].next = (uint32_t)&desc_v[1];
    LCDC_REGS->LCDC_HEOVADDR = &buf_v[0];
    LCDC_REGS->LCDC_HEOVCTRL = LCDC_HEOCTRL_DFETCH(1);
    LCDC_REGS->LCDC_HEOVNEXT = &desc_v[0];

#else
    desc_y[0].addr = &buf_y[0];
    desc_y[0].ctrl = LCDC_HEOCTRL_DFETCH(1);
    desc_y[0].next = (uint32_t)&desc_y[0];
    desc_y[0].reserved = 0; 
    LCDC_REGS->LCDC_HEOADDR = &buf_y[0];
    LCDC_REGS->LCDC_HEOCTRL = LCDC_HEOCTRL_DFETCH(1);
    LCDC_REGS->LCDC_HEONEXT = &desc_y[0];

    desc_u[0].addr = &buf_u[0];
    desc_u[0].ctrl = LCDC_HEOCTRL_DFETCH(1);
    desc_u[0].next = (uint32_t)&desc_u[0];
    desc_u[0].reserved = 0;
    LCDC_REGS->LCDC_HEOUADDR = &buf_u[0];
    LCDC_REGS->LCDC_HEOUCTRL = LCDC_HEOCTRL_DFETCH(1);
    LCDC_REGS->LCDC_HEOUNEXT = &desc_u[0];

    desc_v[0].addr = &buf_v[0];
    desc_v[0].ctrl = LCDC_HEOCTRL_DFETCH(1);
    desc_v[0].next = (uint32_t)&desc_v[0];
    desc_v[0].reserved = 0;
    LCDC_REGS->LCDC_HEOVADDR = &buf_v[0];
    LCDC_REGS->LCDC_HEOVCTRL = LCDC_HEOCTRL_DFETCH(1);
    LCDC_REGS->LCDC_HEOVNEXT = &desc_v[0];
#endif

    LCDC_REGS->LCDC_HEOCFG12 = LCDC_HEOCFG12_GA(0xFF) | LCDC_HEOCFG12_DMA(1) | LCDC_HEOCFG12_OVR(1) | LCDC_HEOCFG12_GAEN(1);
    //LCDC_REGS->LCDC_HEOCFG12 = LCDC_HEOCFG12_GA(0xFF) | LCDC_HEOCFG12_GAEN(1);
    LCDC_REGS->LCDC_HEOCHER = LCDC_HEOCHER_UPDATEEN(1) | LCDC_HEOCHER_CHEN(1);
    //printf("haha %s exit\n\r", __func__);
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    int width = 0, height = 0, i; 
    uint8_t* tptr = NULL;
    /* Check the application's current state. */
    switch ( appData.state )
    {
        case APP_MOUNT_WAIT:
            /* Wait for SDCARD to be Auto Mounted */
            if(appData.sdCardMountFlag == true)
            {
                appData.state = APP_SET_CURRENT_DRIVE;
            }
            break;

        case APP_SET_CURRENT_DRIVE:
            if(SYS_FS_CurrentDriveSet(SDCARD_MOUNT_NAME) == SYS_FS_RES_FAILURE)
            {
                /* Error while setting current drive */
                appData.state = APP_ERROR;
            }
            else
            {
                /* Open a file for reading. */
                appData.state = APP_OPEN_FILE;
            }
            break;

        case APP_OPEN_FILE:
            sprintf(jpg_file_name, "images/%d.jpg", jpg_index);
            appData.fileHandle = SYS_FS_FileOpen(jpg_file_name,
                    (SYS_FS_FILE_OPEN_READ));
            if(appData.fileHandle == SYS_FS_HANDLE_INVALID)
            {
                /* Could not open the file. Error out*/
                appData.state = APP_ERROR;
                printf("Could not open the file\r\n");
            }
            else
            {
                pics.jpg_len = SYS_FS_FileSize(appData.fileHandle);
                appData.state = APP_READ_FILE;
            }
            break;

        case APP_READ_FILE:
            appData.nBytesRead = SYS_FS_FileRead(appData.fileHandle, (void *)pics.jpg_buf, pics.jpg_len);
            if (appData.nBytesRead == -1)
            {
                printf("There was an error while reading the file\r\n");
                SYS_FS_FileClose(appData.fileHandle);
                appData.state = APP_ERROR;
            }
            else if (appData.nBytesRead == 0)
            {
                printf("read 0 len from file[%s]\r\n", jpg_file_name);
                appData.state = APP_ERROR;
            }
            else
            {
                jpg_index++;
                if (jpg_index > END_PIC_NUM)
                    jpg_index = START_PIC_NUM;
                SYS_FS_FileClose(appData.fileHandle);
                appData.state = APP_PLAY_DEMO;            
            }
            break;

        case APP_CYCLE_READ:    

            break;

        case APP_PLAY_DEMO:
            pingpong = 1 - pingpong;        
            djpeg(pics.jpg_buf, pics.jpg_len, buf_y[pingpong], buf_u[pingpong], buf_v[pingpong], &width, &height);
            update_desc(pingpong);
            appData.state = APP_OPEN_FILE;
#ifdef LOG_FPS_CALCULATION
            index++;
#endif
            break;

        case APP_ERROR:
            /* The application comes here when the demo has failed. */

            break;

        case APP_TEST:

            break;

        default:
            break;
    }
}


/*******************************************************************************
 End of File
 */
