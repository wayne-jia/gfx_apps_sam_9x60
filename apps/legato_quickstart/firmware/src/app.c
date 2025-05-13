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
#define APP_FIXED_STR_SIZE 3

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
uint32_t settemp = 71;
uint32_t curtemp = 72;

static leFixedString StrCurTemp;
static leChar StrCurTempBuff[APP_FIXED_STR_SIZE] = {0};
static leFixedString StrSetTemp;
static leChar StrSetTempBuff[APP_FIXED_STR_SIZE] = {0};

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/
void HomeScreen_OnShow(void)
{
    leFixedString_Constructor(&StrCurTemp, StrCurTempBuff, APP_FIXED_STR_SIZE); //Set data store
    StrCurTemp.fn->setFont(&StrCurTemp, (leFont*) &Inter_160);  //Set Font

    leFixedString_Constructor(&StrSetTemp, StrSetTempBuff, APP_FIXED_STR_SIZE); //Set data store
    StrSetTemp.fn->setFont(&StrSetTemp, (leFont*) &Inter_80);  //Set Font
}
// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/
void event_HomeScreen_ButtonWiFi_OnReleased(leButtonWidget* btn)
{
    HomeScreen_image_imgHomeSelect->fn->setImage(HomeScreen_image_imgHomeSelect, (leImage*)&figmaImg_imgHome);
    HomeScreen_image_imgWifi_0->fn->setImage(HomeScreen_image_imgWifi_0, (leImage*)&figmaImg_imgWifiDefault);
    HomeScreen_image_imgSettings_0->fn->setImage(HomeScreen_image_imgSettings_0, (leImage*)&figmaImg_imgSettings);
   
    gfxcHideCanvas(SETTING_CANVAS_ID);
    gfxcShowCanvas(WIFI_CANVAS_ID);
    
    gfxcCanvasUpdate(SETTING_CANVAS_ID);
    gfxcCanvasUpdate(WIFI_CANVAS_ID);
}

void event_HomeScreen_ButtonSetting_OnReleased(leButtonWidget* btn)
{
    HomeScreen_image_imgHomeSelect->fn->setImage(HomeScreen_image_imgHomeSelect, (leImage*)&figmaImg_imgHome);
    HomeScreen_image_imgWifi_0->fn->setImage(HomeScreen_image_imgWifi_0, (leImage*)&figmaImg_imgWifi);
    HomeScreen_image_imgSettings_0->fn->setImage(HomeScreen_image_imgSettings_0, (leImage*)&figmaImg_imgSettingsSelect);
    
    gfxcHideCanvas(WIFI_CANVAS_ID);
    gfxcShowCanvas(SETTING_CANVAS_ID);
    
    gfxcCanvasUpdate(SETTING_CANVAS_ID);
    gfxcCanvasUpdate(WIFI_CANVAS_ID);
}

void event_HomeScreen_ButtonHome_OnReleased(leButtonWidget* btn)
{
    HomeScreen_image_imgHomeSelect->fn->setImage(HomeScreen_image_imgHomeSelect, (leImage*)&figmaImg_imgHomeSelect);
    HomeScreen_image_imgWifi_0->fn->setImage(HomeScreen_image_imgWifi_0, (leImage*)&figmaImg_imgWifi);
    HomeScreen_image_imgSettings_0->fn->setImage(HomeScreen_image_imgSettings_0, (leImage*)&figmaImg_imgSettings);
    
    gfxcHideCanvas(SETTING_CANVAS_ID);
    gfxcHideCanvas(WIFI_CANVAS_ID);
    
    gfxcCanvasUpdate(SETTING_CANVAS_ID);
    gfxcCanvasUpdate(WIFI_CANVAS_ID);
}

void event_HomeScreen_ButtonUp_OnReleased(leButtonWidget* btn)
{
    char cStrBuff[APP_FIXED_STR_SIZE];
    snprintf(cStrBuff, APP_FIXED_STR_SIZE, "%lu", ++settemp);
    StrSetTemp.fn->setFromCStr(&StrSetTemp, cStrBuff);
    HomeScreen_label_lblTargetTempValue->fn->setString(HomeScreen_label_lblTargetTempValue, (leString *) &StrSetTemp); 
}

void event_HomeScreen_ButtonDown_OnReleased(leButtonWidget* btn)
{
    char cStrBuff[APP_FIXED_STR_SIZE];
    snprintf(cStrBuff, APP_FIXED_STR_SIZE, "%lu", --settemp);
    StrSetTemp.fn->setFromCStr(&StrSetTemp, cStrBuff);
    HomeScreen_label_lblTargetTempValue->fn->setString(HomeScreen_label_lblTargetTempValue, (leString *) &StrSetTemp);
}

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
    appData.state = APP_STATE_INIT;

    gfxcSetLayer(HOME_CANVAS_ID, HOME_LAYER_ID);
    gfxcSetLayer(SETTING_CANVAS_ID, SETTING_LAYER_ID);
    gfxcSetLayer(WIFI_CANVAS_ID, WIFI_LAYER_ID);

    gfxcSetWindowPosition(HOME_CANVAS_ID, 0, 0);
    gfxcSetWindowSize(HOME_CANVAS_ID, 800, 480);

    gfxcSetWindowPosition(SETTING_CANVAS_ID, 180, 0);
    gfxcSetWindowSize(SETTING_CANVAS_ID, 620, 480);

    gfxcSetWindowPosition(WIFI_CANVAS_ID, 180, 0);
    gfxcSetWindowSize(WIFI_CANVAS_ID, 620, 480);
    
    gfxcShowCanvas(HOME_CANVAS_ID);
    gfxcShowCanvas(SETTING_CANVAS_ID);
    gfxcShowCanvas(WIFI_CANVAS_ID);
    
    //gfxcSetWindowAlpha(WIFI_CANVAS_ID, 255);

    gfxcCanvasUpdate(HOME_CANVAS_ID);
    gfxcCanvasUpdate(SETTING_CANVAS_ID);
    gfxcCanvasUpdate(WIFI_CANVAS_ID);

    printf("APP_Initialize done.\r\n");
    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;


            if (appInitialized)
            {

                appData.state = APP_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {

            break;
        }

        /* TODO: implement your application state machine.*/


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
