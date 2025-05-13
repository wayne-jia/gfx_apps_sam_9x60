// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#include "definitions.h"
#include "app_screen.h"

/* animation tick period */
#define CLOCK_TICK_TIMER_PERIOD_MS 20
#define ANIM_PERIOD_MS 40

#define MGS_LOGO_HIDEX -225
#define MGS_LOGO_SHOWX 46

#define MCHP_LOGO_HIDEX 320
#define MCHP_LOGO_SHOWX 26

#define EASE_COEFF 2

#define SPLASH_DELAY_MS 300
#define SPLASH_DURATION_MS 300

#define ANIM_PERIOD_TICKS (ANIM_PERIOD_MS/CLOCK_TICK_TIMER_PERIOD_MS)

/* splash screen states */
typedef enum
{
    APP_SPLASH_INIT,
    APP_SPLASH_WAIT_FOR_GUI,
    APP_SPLASH_ANIM_MGS,
    APP_SPLASH_ANIM_PAUSE,
    APP_SPLASH_ANIM_MCHP,
    APP_SPLASH_DONE,
    APP_SPLASH_EXIT,
} APP_SPLASH_STATES;

/* splash screen state variable */
static APP_SPLASH_STATES appSplashState;

/* splash screen tick counters */
static volatile unsigned int tickCount = 0;
static volatile unsigned int animTickCount = 0;
uint32_t animTickCountLast = 0;

/* tick timer handle */
static SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;

extern bool APP_GetDirectBootEnabled(void);

/* tick timer callback */
static void APP_UI_Timer_Callback ( uintptr_t context)
{
    /* Increment tick and animation counters */
    tickCount++;

    if (tickCount % ANIM_PERIOD_TICKS)
        animTickCount++;
}

/* splash screen on show event handler */
void Splash_OnShow(void)
{
    
    if (APP_GetDirectBootEnabled() == true)
    {
        appSplashState = APP_SPLASH_EXIT;
    }
    else
    {
        /* initialize splash screen state */
        appSplashState = APP_SPLASH_INIT;
        
        /* hide logos */
        APP_LE_SETX(Splash_MicrochipLogo_0, MCHP_LOGO_HIDEX);
        APP_LE_SETX(Splash_MGSLogo, MGS_LOGO_HIDEX);
        
        /* register and start tick timers */
        timer = SYS_TIME_CallbackRegisterMS(APP_UI_Timer_Callback, 
                                            1,
                                            CLOCK_TICK_TIMER_PERIOD_MS,
                                            SYS_TIME_PERIODIC);
        SYS_TIME_TimerStart(timer);  
    }
}

void Splash_OnHide(void)
{
    
}

/* splash screen on update event handler. This is periodically called within 
   the GUI library task and manages the GUI state machine */
void Splash_OnUpdate(void)
{
    switch(appSplashState)
    {
        case APP_SPLASH_INIT:
        {
            /* add delay to initialize display */
            appSplashState = APP_SPLASH_WAIT_FOR_GUI;
            SYS_TIME_DelayMS(SPLASH_DELAY_MS, &timer);
            
            break;
        }
        case APP_SPLASH_WAIT_FOR_GUI:
        {
            /* wait until delay expires and gui is done drawing */
            if (leIsDrawing() == LE_FALSE && SYS_TIME_DelayIsComplete(timer))
            {
                appSplashState = APP_SPLASH_ANIM_MGS;
            }
            
            break;
        }
        case APP_SPLASH_ANIM_MGS:
        {
            if (animTickCount != animTickCountLast)
            {
                /* animate MGS logo at animation tick intervals */
                int32_t xmgs = APP_LE_GETX(Splash_MGSLogo);
                int32_t xmchp = APP_LE_GETX(Splash_MicrochipLogo_0);

                int32_t deltax1 = (MGS_LOGO_SHOWX - xmgs) / EASE_COEFF;
                int32_t deltax2 = (MCHP_LOGO_SHOWX - xmchp) / EASE_COEFF;
                                
                if (deltax1 != 0)
                {
                    APP_LE_SETX(Splash_MGSLogo, xmgs + deltax1);
                }
                else
                {
                    APP_LE_SETX(Splash_MGSLogo, MGS_LOGO_SHOWX);
                }
                
                if (deltax2 != 0)
                {
                    APP_LE_SETX(Splash_MicrochipLogo_0, xmchp + deltax2);
                }
                else
                {
                    APP_LE_SETX(Splash_MicrochipLogo_0, MCHP_LOGO_SHOWX);
                }
                
                if (deltax1 == 0 && deltax2 == 0)
                {
                    appSplashState = APP_SPLASH_DONE;
                    SYS_TIME_DelayMS(SPLASH_DURATION_MS, &timer);
                    
                    APP_LE_SETVISIBLE(Splash_MidLine, LE_FALSE);
                }
                
                animTickCountLast = animTickCount;
            }
            
            break;
        }
        case APP_SPLASH_DONE:
        {
            if (SYS_TIME_DelayIsComplete(timer) == true)
            {     
                /* delay is complete, exit splash screen */    
                SYS_TIME_TimerStop(timer); 
                SYS_TIME_TimerDestroy(timer); 
            
                appSplashState = APP_SPLASH_EXIT;
            }
            
            break;
        }
        case APP_SPLASH_EXIT:
        {
            /* show main gauges screen */
            legato_showScreen(screenID_Screen0);
            
            break;
        }
        default:
        {
            break;
        }
    }    
}
