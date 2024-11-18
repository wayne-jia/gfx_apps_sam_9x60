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

#include "app.h"
#include "definitions.h"

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
static bool blur_alpha_high;

static uint32_t prev_tick, tick =0;
static uint32_t prev_sec_tick, sec_tick =0;
static bool screen_show = false;
static uint32_t icon_idx = 0;
// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/



void Screen0_OnShow(void)
{
	LCDC_BrightnessSet(0);
	Panel_Initialize();
	LCDC_BrightnessSet(100);
	TC1_CH0_TimerStart();
	TC1_CH1_TimerStart();
	screen_show = true;
	printf("bl on\r\n");
}


void TC1_CH1_TimerInterruptHandler(TC_TIMER_STATUS status, uintptr_t context)
{
    tick++;
}

void TC1_CH0_TimerInterruptHandler(TC_TIMER_STATUS status, uintptr_t context)
{
    sec_tick++;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

static void PA14_SetOutput(bool set)
{
	GPIO_PA14_IDR();
	GPIO_PA14_PPUER();
	if (set)
		GPIO_PA14_Set();
	else
		GPIO_PA14_Clear();
	GPIO_PA14_OutputEnable();
	GPIO_PA14_PER();
}

static void PA13_SetOutput(bool set)
{
	GPIO_PA13_IDR();
	GPIO_PA13_PPUER();
	if (set)
		GPIO_PA13_Set();
	else
		GPIO_PA13_Clear();
	GPIO_PA13_OutputEnable();
	GPIO_PA13_PER();
}

static void PA12_SetOutput(bool set)
{
	GPIO_PA12_IDR();
	GPIO_PA12_PPUER();
	if (set)
		GPIO_PA12_Set();
	else
		GPIO_PA12_Clear();
	GPIO_PA12_OutputEnable();
	GPIO_PA12_PER();
}

static void PC31_SetOutput(bool set)
{
	GPIO_PC31_IDR();
	GPIO_PC31_PPUER();
	if (set)
		GPIO_PC31_Set();
	else
		GPIO_PC31_Clear();
	GPIO_PC31_OutputEnable();
	GPIO_PC31_PER();
}

/* TODO:  Add any necessary local functions.
*/
static void _LCDC_DelayMS(int ms)
{
	SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;

	if (SYS_TIME_DelayMS(ms, &timer) != SYS_TIME_SUCCESS)
	    return;
	
	while (SYS_TIME_DelayIsComplete(timer) == false);
} 

static void write_command(unsigned char data)
{
	unsigned char i;
	PA14_SetOutput(false);
	PA13_SetOutput(false);
	PA12_SetOutput(false);
	PA13_SetOutput(true);
	
	for (i=0; i<8; i++) {
		PA13_SetOutput(false);
		if (data & 0x80)
			PA12_SetOutput(true);
		else
			PA12_SetOutput(false);

		PA13_SetOutput(true);
		data = data << 1;
	}
	PA14_SetOutput(true); //CS 1
}

static void write_data(unsigned char data)
{
	unsigned char i;
	PA14_SetOutput(false);
	PA13_SetOutput(false);
	PA12_SetOutput(true);
	PA13_SetOutput(true);
	
	for (i=0; i<8; i++) {
		PA13_SetOutput(false);
		if (data & 0x80)
			PA12_SetOutput(true);
		else
			PA12_SetOutput(false);

		PA13_SetOutput(true);
		data = data << 1;
	}
	PA14_SetOutput(true); //CS 1
}

#if 1  //
void BOARD_InitLCD_SPI(void)
{
	PC31_SetOutput(true);
	_LCDC_DelayMS(5);
	PC31_SetOutput(false);
	_LCDC_DelayMS(20);
	PC31_SetOutput(true);
	_LCDC_DelayMS(5);

	write_command(0xFE);
	write_command(0xEF);

	write_command(0xEB);
	write_data(0x14);
	write_command(0x84);
	write_data(0x65);
	write_command(0x85);
	write_data(0xFF);
	write_command(0x86);
	write_data(0xFF);
	write_command(0x87);
	write_data(0xFF);
	write_command(0x88);
	write_data(0x0A);
	write_command(0x89);
	write_data(0x21);
	write_command(0x8A);
	write_data(0x40);
	write_command(0x8B);
	write_data(0x80);
	write_command(0x8C);
	write_data(0x01);
	write_command(0x8D);
	write_data(0x01);
	write_command(0x8E);
	write_data(0xFF);
	write_command(0x8F);
	write_data(0xFF);

	write_command(0xB6);
	write_data(0x00);
	write_data(0x00);

	write_command(0x36);
	write_data(0x48);


	write_command(0x3a);//´«?¸??¡?
	write_data(0x55);///RGB MODE SELECTED

	write_command(0xf6);//½???ýT?
	write_data(0xc6);//RGBmode-16/18bit

	write_command(0xb0);//RGB?ºN?
	write_data(0x42);////40:DE MODE   60:SYNC MODE

	write_command(0xb5);//??T?
	write_data(0x08);//vfp[7:0]      host  8
	write_data(0x09);//vbp[6:0]      host  4
	write_data(0x14);//hbp[4:0]      host 20


	write_command(0x90);
	write_data(0x08);
	write_data(0x08);
	write_data(0x08);
	write_data(0x08);

	write_command(0xBD);
	write_data(0x06);
	///////////add///////////////////////
	write_command(0xA6);
	write_data(0x74);

	write_command(0xBF);
	write_data(0x1C);

	write_command(0xA7);
	write_data(0x45);

	write_command(0xA9);
	write_data(0xBB);

	write_command(0xB8);
	write_data(0x63);
	/////////////////////////////////
	write_command(0xBC);
	write_data(0x00);

	write_command(0xFF);
	write_data(0x60);
	write_data(0x01);
	write_data(0x04);

	write_command(0xC3);
	write_data(0x21);
	write_command(0xC4);
	write_data(0x21);

	write_command(0xC9);
	write_data(0x25);

	write_command(0xBE);
	write_data(0x11);

	write_command(0xE1);
	write_data(0x10);
	write_data(0x0E);

	write_command(0xDF);
	write_data(0x21);
	write_data(0x0c);
	write_data(0x02);

	write_command(0xF0);
	write_data(0x45);
	write_data(0x09);
	write_data(0x08);
	write_data(0x08);
	write_data(0x26);
	write_data(0x2A);

	write_command(0xF1);
	write_data(0x43);
	write_data(0x70);
	write_data(0x72);
	write_data(0x36);
	write_data(0x37);
	write_data(0x6F);

	write_command(0xF2);
	write_data(0x45);
	write_data(0x09);
	write_data(0x08);
	write_data(0x08);
	write_data(0x26);
	write_data(0x2A);

	write_command(0xF3);
	write_data(0x43);
	write_data(0x70);
	write_data(0x72);
	write_data(0x36);
	write_data(0x37);
	write_data(0x6F);

	write_command(0xED);
	write_data(0x1B);
	write_data(0x0B);

	write_command(0xAE);
	write_data(0x77);

	write_command(0xCD);
	write_data(0x63);


	write_command(0x70);
	write_data(0x07);
	write_data(0x07);
	write_data(0x04);
	write_data(0x0E);
	write_data(0x0F);
	write_data(0x09);
	write_data(0x07);
	write_data(0x08);
	write_data(0x03);

	write_command(0xE8);
	write_data(0x24);
	/////////////////////////////////////////////
	write_command(0x60);
	write_data(0x38); //STV1
	write_data(0x0B);
	write_data(0x6D);
	write_data(0x6D);

	write_data(0x39);//STV2
	write_data(0xF0);
	write_data(0x6D);
	write_data(0x6D);


	write_command(0x61);
	write_data(0x38);//STV3
	write_data(0xF4);
	write_data(0x6D);
	write_data(0x6D);

	write_data(0x38);//STV4
	write_data(0xF7);
	write_data(0x6D);
	write_data(0x6D);
	/////////////////////////////////////
	write_command(0x62);
	write_data(0x38);
	write_data(0x0D);
	write_data(0x71);
	write_data(0xED);
	write_data(0x70);
	write_data(0x70);
	write_data(0x38);
	write_data(0x0F);
	write_data(0x71);
	write_data(0xEF);
	write_data(0x70);
	write_data(0x70);

	write_command(0x63);
	write_data(0x38);
	write_data(0x11);
	write_data(0x71);
	write_data(0xF1);
	write_data(0x70);
	write_data(0x70);
	write_data(0x38);
	write_data(0x13);
	write_data(0x71);
	write_data(0xF3);
	write_data(0x70);
	write_data(0x70);
	///////////////////////////////////////////////////////
	write_command(0x64);
	write_data(0x28);
	write_data(0x29);
	write_data(0xF1);
	write_data(0x01);
	write_data(0xF1);
	write_data(0x00);
	write_data(0x07);

	//??
	write_command(0x66);
	write_data(0x3C);
	write_data(0x00);
	write_data(0xCD);
	write_data(0x67);
	write_data(0x45);
	write_data(0x45);
	write_data(0x10);
	write_data(0x00);
	write_data(0x00);
	write_data(0x00);

	write_command(0x67);
	write_data(0x00);
	write_data(0x3C);
	write_data(0x00);
	write_data(0x00);
	write_data(0x00);
	write_data(0x01);
	write_data(0x54);
	write_data(0x10);
	write_data(0x32);
	write_data(0x98);


	write_command(0x74);
	write_data(0x10);
	write_data(0x85);
	write_data(0x80);
	write_data(0x00);
	write_data(0x00);
	write_data(0x4E);
	write_data(0x00);

	write_command(0x98);
	write_data(0x3e);
	write_data(0x07);


	write_command(0x35);
	write_data(0x00);
	write_command(0x21);
	_LCDC_DelayMS(5);
	//--------end gamma setting--------------//

	write_command(0x11);
	_LCDC_DelayMS(5);
	write_command(0x29);
	write_command(0x2C);
}

#else  //??
void BOARD_InitLCD_SPI(void)
{
	printf("Reverse Scan...\r\n");

	PC31_SetOutput(true);
	//dbg_info("read1 RES:%d should be 1\n\r", read_gpio_RES());
	_LCDC_DelayMS(5);
	PC31_SetOutput(false);
	//dbg_info("read2 RES:%d should be 0\n\r", read_gpio_RES());
	_LCDC_DelayMS(20);
	PC31_SetOutput(true);
	//dbg_info("read3 RES:%d should be 1\n\r", read_gpio_RES());
	_LCDC_DelayMS(5);

	write_command(0xFE);
	write_command(0xEF);

	write_command(0xEB);
	write_data(0x14);
	write_command(0x84);
	write_data(0x65);
	write_command(0x85);
	write_data(0xF1);
	write_command(0x86);
	write_data(0x98);
	write_command(0x87);
	write_data(0x28);
	write_command(0x88);
	write_data(0x0A);
	write_command(0x89);
	write_data(0x21);
	write_command(0x8A);
	write_data(0x40);
	write_command(0x8B);
	write_data(0x80);
	write_command(0x8C);
	write_data(0x01);
	write_command(0x8D);
	write_data(0x03);//0x00
	write_command(0x8E);
	write_data(0xDF);
	write_command(0x8F);
	write_data(0x52);

	write_command(0xB6);//??/????
	write_data(0x00);
	write_data(0x40);//GS 

	write_command(0x36);//??XY???,?????
	write_data(0x08);

	write_command(0xf6);//??????
	write_data(0xc6);//RGBmode-16/18bit

	write_command(0xb0);//RGB????
	write_data(0x40);////40:DE MODE   60:SYNC MODE

	write_command(0x3A); //16/18bit??
	write_data(0x55);

	write_command(0xb5);
	write_data(0x08);
	write_data(0x09);
	write_data(0x14);

	write_command(0x90);
	write_data(0x08);
	write_data(0x08);
	write_data(0x08);
	write_data(0x08);

	write_command(0xBD);
	write_data(0x06);

	//write_command(0xA6);
	//write_data(0x74);

	//write_command(0xBF);
	//write_data(0x1C);

	//write_command(0xA7);
	//write_data(0x45);

	write_command(0xA9);
	write_data(0xCC);

	//write_command(0xB8);
	//write_data(0x63);


	write_command(0xBC);
	write_data(0x00);

	write_command(0xFF);
	write_data(0x60);
	write_data(0x01);
	write_data(0x04);

	write_command(0xC3);///1a 1b		
	write_data(0x21);//0x17

	write_command(0xC4);///2a 2b		
	write_data(0x21);//0x17/

	write_command(0xC9);
	write_data(0x25);///vrg1a  2a 0x25

	write_command(0xBE);
	write_data(0x11);

	write_command(0xE1);
	write_data(0x10);
	write_data(0x0E);

	write_command(0xDF);
	write_data(0x21);
	write_data(0x0c);
	write_data(0x02);

	write_command(0xF0);
	write_data(0x45);
	write_data(0x09);
	write_data(0x08);
	write_data(0x08);
	write_data(0x26);
	write_data(0x2A);

	write_command(0xF1);
	write_data(0x43);
	write_data(0x70);
	write_data(0x72);
	write_data(0x36);
	write_data(0x37);
	write_data(0x6F);

	write_command(0xF2);
	write_data(0x45);
	write_data(0x09);
	write_data(0x08);
	write_data(0x08);
	write_data(0x26);
	write_data(0x2A);

	write_command(0xF3);
	write_data(0x43);
	write_data(0x70);
	write_data(0x72);
	write_data(0x36);
	write_data(0x37);
	write_data(0x6F);

	write_command(0xED);
	write_data(0x1B);
	write_data(0x0B);

	//write_command(0xAC);
	//write_data(0x47);
	write_command(0xAE);
	write_data(0x77);
	//write_command(0xCB);
	//write_data(0x02);
	write_command(0xCD);
	write_data(0x63);

	write_command(0x70);
	write_data(0x07);
	write_data(0x07);
	write_data(0x04);
	write_data(0x0E);
	write_data(0x0F);
	write_data(0x09);
	write_data(0x07);
	write_data(0x08);
	write_data(0x03);

	write_command(0xE8);
	write_data(0x24);

	write_command(0x60);
	write_data(0x38);
	write_data(0x0B);
	write_data(0x6D);
	write_data(0x6D);

	write_data(0x39);
	write_data(0xF0);
	write_data(0x6D);
	write_data(0x6D);


	write_command(0x61);
	write_data(0x38);
	write_data(0xF4);
	write_data(0x6D);
	write_data(0x6D);

	write_data(0x38);
	write_data(0xF7);
	write_data(0x6D);
	write_data(0x6D);
	/////////////////////////////////////
	write_command(0x62);
	write_data(0x38);
	write_data(0x0D);
	write_data(0x71);
	write_data(0xED);
	write_data(0x70);
	write_data(0x70);
	write_data(0x38);
	write_data(0x0F);
	write_data(0x71);
	write_data(0xEF);
	write_data(0x70);
	write_data(0x70);

	write_command(0x63);
	write_data(0x38);
	write_data(0x11);
	write_data(0x71);
	write_data(0xF1);
	write_data(0x70);
	write_data(0x70);
	write_data(0x38);
	write_data(0x13);
	write_data(0x71);
	write_data(0xF3);
	write_data(0x70);
	write_data(0x70);
	///////////////////////////////////////////////////////
	write_command(0x64);
	write_data(0x28);
	write_data(0x29);
	write_data(0xF1);
	write_data(0x01);
	write_data(0xF1);
	write_data(0x00);
	write_data(0x07);


	//·´?
	write_command(0x66);
	write_data(0x3C);
	write_data(0x00);
	write_data(0x98);
	write_data(0x10);
	write_data(0x32);
	write_data(0x45);
	write_data(0x01);
	write_data(0x00);
	write_data(0x00);
	write_data(0x00);

	write_command(0x67);
	write_data(0x00);
	write_data(0x3C);
	write_data(0x00);
	write_data(0x00);
	write_data(0x00);
	write_data(0x10);
	write_data(0x54);
	write_data(0x67);
	write_data(0x45);
	write_data(0xcd);
	////////////////////////////////////////////////

	write_command(0x74);
	write_data(0x10);
	write_data(0x85);
	write_data(0x80);
	write_data(0x00);
	write_data(0x00);
	write_data(0x4E);
	write_data(0x00);

	write_command(0x98);
	write_data(0x3e);
	write_data(0x07);
	write_command(0x99);
	write_data(0x3e);
	write_data(0x07);

	write_command(0x35);//?????
	write_command(0x21);//????
	_LCDC_DelayMS(5);

	write_command(0x11);//??
	_LCDC_DelayMS(5);
	write_command(0x29);
	write_command(0x2C);
}
#endif


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
#if 0
void LCDC_REG_Dump(void)
{
	printf("PMC_REGS->PMC_PCR: %x\r\n", PMC_REGS->PMC_PCR);
	printf("LCDC_REGS->LCDC_LCDCFG0: %x\r\n", LCDC_REGS->LCDC_LCDCFG0);
	printf("LCDC_REGS->LCDC_LCDCFG1: %x\r\n", LCDC_REGS->LCDC_LCDCFG1);
	printf("LCDC_REGS->LCDC_LCDCFG2: %x\r\n", LCDC_REGS->LCDC_LCDCFG2);
	printf("LCDC_REGS->LCDC_LCDCFG3: %x\r\n", LCDC_REGS->LCDC_LCDCFG3);
	printf("LCDC_REGS->LCDC_LCDCFG4: %x\r\n", LCDC_REGS->LCDC_LCDCFG4);
	printf("LCDC_REGS->LCDC_LCDCFG5: %x\r\n", LCDC_REGS->LCDC_LCDCFG5);
	printf("LCDC_REGS->LCDC_LCDCFG6: %x\r\n", LCDC_REGS->LCDC_LCDCFG6);
	printf("LCDC_REGS->LCDC_BASECFG0: %x\r\n", LCDC_REGS->LCDC_BASECFG0);
	printf("LCDC_REGS->LCDC_BASECFG1: %x\r\n", LCDC_REGS->LCDC_BASECFG1);
	printf("LCDC_REGS->LCDC_BASECFG2: %x\r\n", LCDC_REGS->LCDC_BASECFG2);
	printf("LCDC_REGS->LCDC_BASECFG3: %x\r\n", LCDC_REGS->LCDC_BASECFG3);
	printf("LCDC_REGS->LCDC_BASECFG4: %x\r\n", LCDC_REGS->LCDC_BASECFG4);
	printf("LCDC_REGS->LCDC_BASECFG5: %x\r\n", LCDC_REGS->LCDC_BASECFG5);
	printf("LCDC_REGS->LCDC_BASECFG6: %x\r\n", LCDC_REGS->LCDC_BASECFG6);
}


static void pulseBlur(void)
{
    if(blur_alpha_high == true)
    {
        blur_alpha_high = false;
        gfxcStartEffectFade(LOGO_CANVAS_ID,
                                BLUR_ALPHA_HIGH,
                                BLUR_ALPHA_LOW,
                                10);
    }
    else
    {
        blur_alpha_high = true;
        gfxcStartEffectFade(LOGO_CANVAS_ID,
                                BLUR_ALPHA_LOW,
                                BLUR_ALPHA_HIGH,
                                10);
    }
}

static void icon_seqence(bool hide)
{
	switch (icon_idx)
	{
		case 0:
			Screen0_ImageWidget_1->fn->setVisible(Screen0_ImageWidget_1, hide);
			break;

		case 1:
			Screen0_ImageWidget_2->fn->setVisible(Screen0_ImageWidget_2, hide);
			break;

		case 2:
			Screen0_ImageWidget_3->fn->setVisible(Screen0_ImageWidget_3, hide);
			break;

		case 3:
			Screen0_ImageWidget_4->fn->setVisible(Screen0_ImageWidget_4, hide);
			break;

		case 4:
			Screen0_ImageWidget_5->fn->setVisible(Screen0_ImageWidget_5, hide);
			break;

		case 5:
			Screen0_ImageWidget_6->fn->setVisible(Screen0_ImageWidget_6, hide);
			break;

		case 6:
			Screen0_ImageWidget_7->fn->setVisible(Screen0_ImageWidget_7, hide);
			break;

		case 7:
			Screen0_ImageWidget_8->fn->setVisible(Screen0_ImageWidget_8, hide);
			break;

		default:
			break;
	}
	
}
#endif


void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;
	blur_alpha_high = true;
	//LCDC_REG_Dump();

	TC1_CH0_TimerCallbackRegister(TC1_CH0_TimerInterruptHandler, (uintptr_t) NULL); 
    TC1_CH1_TimerCallbackRegister(TC1_CH1_TimerInterruptHandler, (uintptr_t) NULL); 
 
    gfxcSetLayer(BACKGROUND_CANVAS_ID, BACKGROUND_LAYER_ID);
	gfxcSetLayer(BLUR_CANVAS_ID, BLUR_LAYER_ID);
	// gfxcSetLayer(LOGO_CANVAS_ID, LOGO_LAYER_ID);
    // gfxcSetLayer(WELCOME_CANVAS_ID, WELCOME_LAYER_ID);

    gfxcSetWindowPosition(BACKGROUND_CANVAS_ID, 0, 0);
    gfxcSetWindowSize(BACKGROUND_CANVAS_ID, 240, 240);

	gfxcSetWindowPosition(BLUR_CANVAS_ID, 52, 97);
    gfxcSetWindowSize(BLUR_CANVAS_ID, 136, 46);

	// gfxcSetWindowPosition(LOGO_CANVAS_ID, 80, 80);
    // gfxcSetWindowSize(LOGO_CANVAS_ID, 80, 80);

    // gfxcSetWindowPosition(WELCOME_CANVAS_ID, 50, 71);
    // gfxcSetWindowSize(WELCOME_CANVAS_ID, 146, 100);
    
    gfxcShowCanvas(BACKGROUND_CANVAS_ID);
	gfxcShowCanvas(BLUR_CANVAS_ID);
	// gfxcShowCanvas(LOGO_CANVAS_ID);
    // gfxcHideCanvas(WELCOME_CANVAS_ID);
    
    gfxcCanvasUpdate(BACKGROUND_CANVAS_ID);
	gfxcCanvasUpdate(BLUR_CANVAS_ID);
	// gfxcCanvasUpdate(LOGO_CANVAS_ID);
    // gfxcCanvasUpdate(WELCOME_CANVAS_ID);
	//printf("APP_Initialized\r\n");
	
}

void Panel_Initialize(void)
{
    BOARD_InitLCD_SPI();
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
	static uint8_t  sec2=0;
	static uint32_t ms2 = 0;
    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            if (tick != prev_tick)
			{
				ms2++;            
                prev_tick = tick; 
                if(ms2>800)
                {
                    ms2=0;
					switch (icon_idx++)
					{
						case 0:
							Screen0_bper->fn->setString(Screen0_bper, (leString*)&string_s20);
							gfxcSetPixelBuffer(BLUR_CANVAS_ID,
												135,
												45,
												GFX_COLOR_MODE_RGBA_8888,
												(void *) b20.buffer.pixels);
							gfxcCanvasUpdate(BLUR_CANVAS_ID);
							break;
						
						case 1:
							Screen0_bper->fn->setString(Screen0_bper, (leString*)&string_s40);
							gfxcSetPixelBuffer(BLUR_CANVAS_ID,
												135,
												45,
												GFX_COLOR_MODE_RGBA_8888,
												(void *) b40.buffer.pixels);
							gfxcCanvasUpdate(BLUR_CANVAS_ID);
							break;

						case 2:
							Screen0_bper->fn->setString(Screen0_bper, (leString*)&string_s60);
							gfxcSetPixelBuffer(BLUR_CANVAS_ID,
												135,
												45,
												GFX_COLOR_MODE_RGBA_8888,
												(void *) b60.buffer.pixels);
							gfxcCanvasUpdate(BLUR_CANVAS_ID);
							break;

						case 3:
							Screen0_bper->fn->setString(Screen0_bper, (leString*)&string_s80);
							gfxcSetPixelBuffer(BLUR_CANVAS_ID,
												135,
												45,
												GFX_COLOR_MODE_RGBA_8888,
												(void *) b80.buffer.pixels);
							gfxcCanvasUpdate(BLUR_CANVAS_ID);
							break;

						case 4:
							Screen0_bper->fn->setString(Screen0_bper, (leString*)&string_s100);
							gfxcSetPixelBuffer(BLUR_CANVAS_ID,
												135,
												45,
												GFX_COLOR_MODE_RGBA_8888,
												(void *) b100.buffer.pixels);
							gfxcCanvasUpdate(BLUR_CANVAS_ID);
							break;

						default:
							icon_idx = 0;
							appData.state = APP_STATE_FADEOUT_LOGO;
							break;
					}

                }
			}
            break;
        }

		case APP_STATE_FADEOUT_LOGO:
        {
			gfxcStartEffectFade(BLUR_CANVAS_ID, FADE_IN_END_ALPHA, FADE_IN_START_ALPHA, 10);
			appData.state = APP_STATE_FADEIN_LOGO;

            break;
        }

		case APP_STATE_FADEIN_LOGO:
        {
			if (sec_tick != prev_sec_tick)
            {   
				sec2++;            
                prev_sec_tick = sec_tick; 
                if(sec2>2)
                {
                    sec2=0;
					gfxcStartEffectFade(BLUR_CANVAS_ID, FADE_IN_START_ALPHA, FADE_IN_END_ALPHA, 10);
                    appData.state = APP_STATE_RUNNING;
                }
            }

            break;
        }

		case APP_STATE_RUNNING:
        {
			if (sec_tick != prev_sec_tick)
            {   
				sec2++;            
                prev_sec_tick = sec_tick; 
                if(sec2>2)
                {
                    sec2=0;
                    appData.state = APP_STATE_INIT;
                }
            }

            break;
        }

        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
