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

#include <stdbool.h>
#include <stdio.h>

#include "definitions.h"
#include "app_screen.h"

#define DEMO_MODE_ENABLED 1 /* Enables demo after idle period */

#ifdef MGS_SIM
#define DEMO_IDLE_PERIO_MS 5000 //5 seconds idle timeout
#else
#define DEMO_IDLE_PERIO_MS 30000 //30 seconds idle timeout
#endif

/* Increment/decrement units */
#define MAX_DELTA_GAUGE 8
#define MAX_DELTA_TACHO 4
#define DELTA_EASE_COEFF 2
#define SPEEDO_INC 1
#define TACHO_INC 3
#define SPEEDO_INC_POR 8
#define TACHO_INC_POR 6

/* PI constant */
#define M_PI 3.14159265358979323846

/* Max gauge values */
#define MAX_TACHO_VALUE_x100 87
#define MAX_SPEEDO_VALUE 145
#define MAX_GEAR_VALUE 6

/* Tick and animation timer defs */
#define CLOCK_TICK_TIMER_PERIOD_MS 10
#define ANIM_PERIOD_MS 60 /* 16fps */
#define TURN_LIGHT_PERIOD_MS 500
#define GEAR_INC_PERIOD_MS 80
#define USAGE_PERIOD_MS 1000
#define ANIM_PERIOD_TICKS (ANIM_PERIOD_MS/CLOCK_TICK_TIMER_PERIOD_MS)
#define TURN_LIGHT_PERIOD_TICKS (TURN_LIGHT_PERIOD_MS/CLOCK_TICK_TIMER_PERIOD_MS)
#define GEAR_INC_PERIOD_TICKS (ANIM_PERIOD_MS/CLOCK_TICK_TIMER_PERIOD_MS)
#define DEMO_IDLE_PERIOD_TICKS (DEMO_IDLE_PERIO_MS/CLOCK_TICK_TIMER_PERIOD_MS)
#define NUM_COUNT_SEC_TICK (1000/CLOCK_TICK_TIMER_PERIOD_MS)
#define USAGE_PERIOD_TICKS (USAGE_PERIOD_MS/CLOCK_TICK_TIMER_PERIOD_MS)

/* widget hide and show positions */
#define MPH_HIDE_X 290
#define MPH_SHOW_X 115
#define SPEED_HIDE_Y -160
#define SPEED_SHOW_Y 0
#define DIRECTION_ARROWS_SHOW_Y 3
#define DIRECTION_ARROWS_HIDE_Y 70
#define DIRECTIONS_SHOW_X 75
#define DIRECTIONS_HIDE_X 320

/* Active radius for manual control */
#define MIN_TOUCH_RADIUS_PIX 130

/* Default range values */
#define RANGE_VALUE_MAX 400
#define RANGE_VALUE_DEFAULT 281

/* Fix strings lengths */
#define RANGE_VALUE_STR_SIZE 4
#define SPEEDO_VALUE_STR_SIZE 4
#define GEAR_VALUE_STR_SIZE 3
#define METRICS_STR_SIZE 32

//Calibrated coeff and formulas for gauge value and arc angle
#define G_CANGLE_AT_140 7
#define G_CANGLE_AT_0 236
#define G_GET_VALUE_FROM_CANGLE(angle) (((140 * angle)/(G_CANGLE_AT_140 - G_CANGLE_AT_0)) ) - (((140 * G_CANGLE_AT_0) / (G_CANGLE_AT_140 - G_CANGLE_AT_0)) )
#define G_GET_ANGLE_FROM_VALUE(value) (((value + ((140 * G_CANGLE_AT_0) / (G_CANGLE_AT_140 - G_CANGLE_AT_0))) * (G_CANGLE_AT_140 - G_CANGLE_AT_0) / 140))

//Calibrated coeff and formulas for tach value and arc angle
#define T_CANGLE_AT_80 2
#define T_CANGLE_AT_0 134
#define T_GET_VALUE_FROM_CANGLE(angle) (((angle - T_CANGLE_AT_0) * 80)/(T_CANGLE_AT_80 - T_CANGLE_AT_0))
#define T_GET_ANGLE_FROM_VALUE(value) (((T_CANGLE_AT_80 - T_CANGLE_AT_0) * value) / 80 + T_CANGLE_AT_0 + 1)

/* application screen states */
typedef enum
{
    APP_SCREEN_INIT,
    APP_SCREEN_WAIT_FOR_GUI,
    APP_SCREEN_POR_TEST,
    APP_SCREEN_POR_TEST_OK,
    APP_SCREEN_POR_ANIM1,
    APP_SCREEN_POR_ANIM2,
    APP_SCREEN_POR_ANIM3,
    APP_SCREEN_IDLE,
    APP_SCREEN_START_DEMO,
    APP_SCREEN_DEMO,
    APP_SCREEN_STOP,
} APP_SCREEN_STATES;

/* application events */
typedef enum
{
    APP_SCREEN_EVT_DEMO,
    APP_SCREEN_EVT_IDLE_ON,
    APP_SCREEN_EVT_IDLE_OFF,
    APP_SCREEN_EVT_LEFT_TURN,
    APP_SCREEN_EVT_RIGHT_TURN,
    APP_SCREEN_EVT_MAX,
} APP_SCREEN_EVENTS;

extern uint32_t tasksGetGFXUsage(void);
extern unsigned int FreeTask_Usage(void);

/* TODO:  Add any necessary local functions.
*/
static void appSetGaugeValue(int32_t value);
static void appSetTachoValue(int32_t value);

/* Fixed string object and buffer for range label */
static leFixedString rangeValueStr;
static leChar rangeValueStrBuff[RANGE_VALUE_STR_SIZE ] = {0};

/* Fixed string object and buffer for speed label */
static leFixedString speedoValueStr;
static leChar speedoValueStrBuff[SPEEDO_VALUE_STR_SIZE] = {0};

/* Fixed string object and buffer for gear label */
static leFixedString gearValueStr;
static leChar gearValueStrBuff[GEAR_VALUE_STR_SIZE] = {0};

/* Fixed string object and buffer for app metrics label */
static leFixedString metricsStr;
static leChar metricsStrBuff[METRICS_STR_SIZE] = {0};

/* timer handle */
static SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;

/* counters for application, animation and idle ticks */
static volatile unsigned int tickCount = 0;
static volatile unsigned int animTickCount = 0;
static volatile unsigned int idleTickCount = 0;
static unsigned lastTickCount = 0;

/* screen event flags */
static volatile uint32_t screenEvents;

/* Sec timer counter for fps */
static volatile unsigned int secCount = 0;
static unsigned int secCountLast = 0;              

static uint32_t turnLightIndex = 0;

/* current values for range, gear, speed, and tacho */
static int32_t rangeValue = 0;
static int32_t gearValue = 0;
static int32_t gaugeValue = 0;
static int32_t tachoValue = 0;

/* current increment values for speed and tacho */
static int32_t inc = SPEEDO_INC, tachoInc = TACHO_INC;  

/* Target speed and tacho values. 
   These are used during manual control */
static int32_t tGaugeValue = 0;
static int32_t tTachoValue = 0;

/* Task usage value */
static unsigned int cpu_free;
static unsigned int last_frame_count = 0;
static unsigned int fps;

/* Turn signals enable states */
bool rightTurnEnabled = false, leftTurnEnabled = false;

/* Screen state variable */
static APP_SCREEN_STATES screenState;

/* Direct boot flag (no splash animation) */
bool appDirectUIBoot = 0;

/* Array for all panel widget variables */
static leWidget ** panelWidgets[] =
{
    (leWidget **) &Screen0_MicrochipLogo,
    (leWidget **) &Screen0_MicrochipLogo_0,
    (leWidget **) &Screen0_IndicatorsPanel,
    (leWidget **) &Screen0_TurnModePanel,
    (leWidget **) &Screen0_SpeedoValuePanel,
    (leWidget **) &Screen0_Directions,
    (leWidget **) &Screen0_RangePanel,
    (leWidget **) &Screen0_StartButton,
};

static void appSetGaugeLabelValue(int32_t value);

/* Custom arc widget API for updating center angle */
extern leResult updateCenterAngle(leArcWidget* _this,
                               int32_t angle);

/* API to enable/disable direct boot. Direct boot disables splash screen 
   animations */
void APP_SetDirectBootEnabled(bool enabled)
{
    appDirectUIBoot = enabled;
}

/* API to check if direct boot is enabled */
bool APP_GetDirectBootEnabled(void)
{
    return appDirectUIBoot;
}

/* Helper function to set screen event flags */
static void APP_SetScreenEvent(APP_SCREEN_EVENTS event)
{
    screenEvents |= (1u << event);
}

/* Helper function to clear all screen events */
static void APP_ClearScreenEvents(void)
{
    screenEvents = 0;
}

/* Helper function to get and clear a screen event */
static bool APP_GetScreenEvent(APP_SCREEN_EVENTS event)
{
    bool eventSet = (screenEvents >> event) & 1u;

    screenEvents = screenEvents & ~(1u << event);

    return eventSet;
}

/* Event filter for manual gauge control */
static leBool ManualControl_filterEvent(leWidget* target, leWidgetEvent* evt, void* data)
{
    leBool retval = LE_FALSE;    
    lePoint pnt;
    
    pnt.x = ((leWidgetEvent_TouchDown *) evt)->x;
    pnt.y = ((leWidgetEvent_TouchDown *) evt)->y;      
    
    switch(evt->id)
    {
        /* touch down and move events */
        case LE_EVENT_TOUCH_MOVE:         
        case LE_EVENT_TOUCH_DOWN:
        {
            lePoint lPt;
            double angle;
            uint32_t dAngle;
            int32_t rad;
            int32_t mag;
           
            /* reset idle timer */
            APP_SetScreenEvent(APP_SCREEN_EVT_IDLE_OFF);
            
            evt->accepted = LE_TRUE;
            evt->owner = target;
            
            /* translate touch point to local space and convert to polar */
            leUtils_PointScreenToLocalSpace(target, &pnt);
            
            /* Determine touch point in full cartesian */
            lPt.x = pnt.x - target->rect.width / 2;
            lPt.y = target->rect.height / 2 - pnt.y;
                        
            /* Convert to polar coordinates */
            mag = (lPt.x * lPt.x) + (lPt.y * lPt.y);
            rad = leSqrt((float)mag);
            rad = leRound(rad);

            /* if touch point is within the active area (radius), process */
            if (rad >= MIN_TOUCH_RADIUS_PIX)
            {
                angle = (leAtan((double) lPt.y / (double) lPt.x));
                
                if (lPt.x >= 0)
                {
                    dAngle = (lPt.y >= 0) ? (angle * 180) / M_PI : 360 + ((angle * 180) / M_PI);
                }
                else 
                {
                    dAngle = (lPt.y >= 0) ? 180 + ((angle * 180) / M_PI) : 180 + ((angle * 180) / M_PI);
                }
                
                /* Check if angle is in speedo or tacho region, and set target values.
                   screen update function will increment/decrement the values to reach
                   the set target values */
                if (target == Screen0_TouchPanelTacho)
                {
                    /* set target tacho value */
                    if (dAngle < 212 && dAngle > 69)
                    {
                        int32_t tAngle = dAngle - 71;
                        tTachoValue = T_GET_VALUE_FROM_CANGLE(tAngle);
                    }
                }
                else if (target == Screen0_TouchPanelSpeedo)
                {
                    /* set target speedo value. */
                    if (dAngle < 212 || dAngle > 328)
                    {
                        int32_t cAngle = (dAngle < 212) ? dAngle + 32 : 32 - (360 - dAngle);
                        tGaugeValue = G_GET_VALUE_FROM_CANGLE(cAngle);
                    }
                }
            }
            
            retval = LE_TRUE;
            
            break;
        }   
        /* Nothing to do on touch up events */
        case LE_EVENT_TOUCH_UP:            
        {
            evt->accepted = LE_TRUE;
                    
            retval = LE_TRUE;

            break;        
        }
        default:
            break;
    }
    
   return retval;
}

/* structure for widget event filter */
static leWidgetEventFilter ManualControl_eventFilter =
{
    ManualControl_filterEvent,
    NULL
};

/* screen tick, idle and animation timer callback */
static void APP_UI_Timer_Callback ( uintptr_t context)
{
    tickCount++;
    idleTickCount++;
    
    if (tickCount % ANIM_PERIOD_TICKS)
        animTickCount++;
    
    if (tickCount % NUM_COUNT_SEC_TICK == 0)
    {
        if (leRenderer_GetDrawCount() > last_frame_count)
        {
            fps = leRenderer_GetDrawCount() - last_frame_count;
            last_frame_count = leRenderer_GetDrawCount();
        }
        else if (leRenderer_GetDrawCount() < last_frame_count)
        {
            last_frame_count = leRenderer_GetDrawCount();

            fps = 0;
        }        
        secCount++;
    }
}

/* Helper function to set gear value label */
static void appSetGearValue(uint32_t value)
{
    char valueCStr[GEAR_VALUE_STR_SIZE] = {0};
    
    value = (value <= MAX_GEAR_VALUE) ?  value : MAX_GEAR_VALUE;

    snprintf(valueCStr, GEAR_VALUE_STR_SIZE, "%lu", value);
        
    gearValueStr.fn->setFromCStr(&gearValueStr, valueCStr);
    Screen0_GearValueLabel->fn->setString(Screen0_GearValueLabel, (leString *) &gearValueStr);         
    
}

/* Helper function to set gear gauge arc by value */
static void appSetGaugeValue(int32_t value)
{
    int32_t angle;
    
    value = (value <= MAX_SPEEDO_VALUE) ? value : MAX_SPEEDO_VALUE;
    
    angle = G_GET_ANGLE_FROM_VALUE(value);
            
    updateCenterAngle(Screen0_SpeedArc, angle);
}

/* Helper function to set metrics label */
void appSetMetricsValue(uint32_t fps, uint32_t usage)
{
    char metricsCStr[METRICS_STR_SIZE] = {0};
    
    if (usage > 0)
    {
        snprintf(metricsCStr, METRICS_STR_SIZE, "%lu fps, CPU %lu%% ", fps, usage);
    }
    else
    {
        snprintf(metricsCStr, METRICS_STR_SIZE, "%lu fps, CPU <1%% ", fps);
    }
        
    metricsStr.fn->setFromCStr(&metricsStr, metricsCStr);
    Screen0_MetricsLabel->fn->setString(Screen0_MetricsLabel, (leString *) &metricsStr);   
}

/* Helper function to set gear gauge label by value */
static void appSetGaugeLabelValue(int32_t value)
{
    char valueCStr[SPEEDO_VALUE_STR_SIZE] = {0};
    
    value = (value <= MAX_SPEEDO_VALUE) ? value : MAX_SPEEDO_VALUE;
    value = (value < 0) ? 0 : value;
    
    snprintf(valueCStr, SPEEDO_VALUE_STR_SIZE, "%lu", value);
        
    speedoValueStr.fn->setFromCStr(&speedoValueStr, valueCStr);
    Screen0_SpeedoValueLabel->fn->setString(Screen0_SpeedoValueLabel, (leString *) &speedoValueStr);      
}

/* Helper function to set range label by value */
static void appSetRangeLabelValue(int32_t value)
{
    char valueCStr[RANGE_VALUE_STR_SIZE] = {0};
    
    value = (value <= RANGE_VALUE_MAX) ? value : RANGE_VALUE_MAX;
    value = (value < 0) ? 0 : value;
    
    snprintf(valueCStr, RANGE_VALUE_STR_SIZE, "%lu", value);
        
    rangeValueStr.fn->setFromCStr(&rangeValueStr, valueCStr);
    Screen0_RangeValueLabel->fn->setString(Screen0_RangeValueLabel, (leString *) &rangeValueStr);      
}

/* Helper function to set range bar by value */
static void appSetRangeBarValue(int32_t value)
{
    uint32_t w;
    
    value = (value <= RANGE_VALUE_MAX) ? value : RANGE_VALUE_MAX;
    value = (value < 0) ? 0 : value;
    
    w = (value * APP_LE_GETWIDTH(Screen0_RangeValueBarBase)) / RANGE_VALUE_MAX;
    
    APP_LE_SETWIDTH(Screen0_RangeValueBar, w);
}

/* Helper function to set tacho gauge by value */
static void appSetTachoValue(int32_t value)
{
    int32_t angle;
    
    #define TCENTER_ANGLE_AT_80 108
    #define TCENTER_ANGLE_AT_0 8    
    
    value = (value <= MAX_TACHO_VALUE_x100) ? value : MAX_TACHO_VALUE_x100;
    
    angle = T_GET_ANGLE_FROM_VALUE(value);
    
    updateCenterAngle(Screen0_TachoArc, angle);
}

/* Helper function query task usage and frame rates */
void Screen0_UpdateMetrics(void)
{
    printf("===========STAT ============ \r\n");
    cpu_free = FreeTask_Usage();
    secCountLast = secCount;

    printf("fps : %d \r\n", fps);
    printf("============================ \r\n");

    {
        appSetMetricsValue(fps, 100 - cpu_free);
    }    
}

void Screen0_OnShow(void)
{
    /* Initialize fixed strings for labels */
    leFixedString_Constructor(&speedoValueStr, speedoValueStrBuff, SPEEDO_VALUE_STR_SIZE);
    speedoValueStr.fn->setFont(&speedoValueStr, (const leFont* ) &SpeedoFont); 
    
    leFixedString_Constructor(&gearValueStr, gearValueStrBuff, GEAR_VALUE_STR_SIZE);
    gearValueStr.fn->setFont(&gearValueStr, (const leFont* ) &GearNumFont); 
    
    leFixedString_Constructor(&rangeValueStr, rangeValueStrBuff, RANGE_VALUE_STR_SIZE);
    rangeValueStr.fn->setFont(&rangeValueStr, (const leFont* ) &DistanceFont); 
    
    leFixedString_Constructor(&metricsStr, metricsStrBuff, METRICS_STR_SIZE);
    metricsStr.fn->setFont(&metricsStr, (const leFont* ) &Font0); 
    
    /* Initialize tacho, speedo and range values and gauges */
    tachoValue = 0;
    gaugeValue = 0;
    rangeValue = 0;
    
    appSetTachoValue(tachoValue);
    appSetGaugeValue(gaugeValue);
    appSetGaugeLabelValue(gaugeValue);
    
    appSetRangeLabelValue(rangeValue);
    appSetRangeBarValue(rangeValue);
    
    /* Clear all events */
    APP_ClearScreenEvents();
    
    /* register widget event filter callback for manual gauge control */
    APP_LE_SETEVENTFILTER(Screen0_TouchPanelSpeedo, ManualControl_eventFilter);
    APP_LE_SETEVENTFILTER(Screen0_TouchPanelTacho, ManualControl_eventFilter);
    
    /* Register and start screen tick timer */
    APP_LE_SETVISIBLE(Screen0_MetricsButton, LE_FALSE);
    APP_LE_SETVISIBLE(Screen0_MetricsLabel, LE_FALSE);
    
    timer = SYS_TIME_CallbackRegisterMS(APP_UI_Timer_Callback, 
                                        1,
                                        CLOCK_TICK_TIMER_PERIOD_MS,
                                        SYS_TIME_PERIODIC);
    SYS_TIME_TimerStart(timer);

    SYS_TIME_DelayMS(500, &timer);    
    
    if (APP_GetDirectBootEnabled() == true)
    {
        APP_LE_SETVISIBLE(Screen0_MicrochipLogo_0, LE_FALSE);
            
        screenState = APP_SCREEN_IDLE;    
    }
    else
    {
        uint32_t i;
        
        /* hide all panels, they will be shown one by one during 
           screen initialization state */
        for (i = 0; i < sizeof(panelWidgets)/sizeof(leWidget **); i++)
        {
            ((leWidget *)(*panelWidgets[i]))->fn->setVisible(((leWidget *)(*panelWidgets[i])), LE_FALSE);
        }

        /* Show logos to match splash screen */
        APP_LE_SETVISIBLE(Screen0_MicrochipLogo_0, LE_TRUE);
        APP_LE_SETVISIBLE(Screen0_SpeedoValuePanel, LE_TRUE);

        /* Hide the other widgets */
        APP_LE_SETY(Screen0_SpeedoValueLabel, SPEED_HIDE_Y);
        APP_LE_SETX(Screen0_mphLabel, MPH_HIDE_X);

        APP_LE_SETY(Screen0_DirectionArrows, DIRECTION_ARROWS_HIDE_Y);
        APP_LE_SETX(Screen0_DirectionLabel, DIRECTIONS_HIDE_X);
        APP_LE_SETX(Screen0_DistanceLabel, DIRECTIONS_HIDE_X);
        
        screenState = APP_SCREEN_INIT;         
    }
}

void Screen0_OnHide(void)
{
    
}

void Screen0_OnUpdate(void)
{
    switch(screenState)
    {
        case APP_SCREEN_INIT:
        {
            screenState = APP_SCREEN_WAIT_FOR_GUI;
            
            break;
        }
        /* Wait for GUI to complete drawing */
        case APP_SCREEN_WAIT_FOR_GUI:
        {
            if (leIsDrawing() == LE_FALSE)
            {
                screenState = APP_SCREEN_POR_TEST;
            }
            
            break;
        }
        /* Show gauge reset animation from 0 to max */
        case APP_SCREEN_POR_TEST:
        {
            Screen0_LeftTurnImageSeq->fn->showImage(Screen0_LeftTurnImageSeq, 1);
            Screen0_RightTurnImageSeq->fn->showImage(Screen0_RightTurnImageSeq, 1);
            
            if(lastTickCount != tickCount)
            {
                if ((tickCount % ANIM_PERIOD_TICKS) == 0)
                {
                    gaugeValue = (gaugeValue <= MAX_SPEEDO_VALUE - SPEEDO_INC_POR) ? 
                                 gaugeValue + SPEEDO_INC_POR : MAX_SPEEDO_VALUE;

                    appSetGaugeValue(gaugeValue);
                    appSetGaugeLabelValue(gaugeValue);
                    
                    tachoValue = (tachoValue <= MAX_TACHO_VALUE_x100 - TACHO_INC_POR) ? 
                                 tachoValue + TACHO_INC_POR : MAX_TACHO_VALUE_x100;
                    
                    appSetTachoValue(tachoValue);
                    
                    gearValue = (gearValue <= MAX_GEAR_VALUE - 1) ? gearValue + 1 : MAX_GEAR_VALUE;
                        
                        appSetGearValue(gearValue);
                }
                
                lastTickCount = tickCount;
            }            

            if (gaugeValue >= MAX_SPEEDO_VALUE && tachoValue >= MAX_TACHO_VALUE_x100 && gearValue >= MAX_GEAR_VALUE)
            {
                screenState = APP_SCREEN_POR_TEST_OK;
            }
            
            break;
        }
        /* Decrement gauges  back to 0 */
        case APP_SCREEN_POR_TEST_OK: //Fall through, no break
        case APP_SCREEN_STOP:
        {
            if(lastTickCount != tickCount)
            {
                if ((tickCount % ANIM_PERIOD_TICKS) == 0)
                {
                    gaugeValue = (gaugeValue >= SPEEDO_INC_POR) ? 
                                 gaugeValue - SPEEDO_INC_POR : 0;

                    appSetGaugeValue(gaugeValue);
                    appSetGaugeLabelValue(gaugeValue);
                    
                    tachoValue = (tachoValue >= TACHO_INC_POR) ? 
                                 tachoValue - TACHO_INC_POR : 0;
                    
                    appSetTachoValue(tachoValue);
                    
                    gearValue = (gearValue >= 1) ? gearValue - 1 : 0;
                        
                    appSetGearValue(gearValue);
                }
                
                lastTickCount = tickCount;
            }            

            if (gaugeValue == 0 && 
                tachoValue == 0 && 
                gearValue == 0)
            {
                Screen0_LeftTurnImageSeq->fn->showImage(Screen0_LeftTurnImageSeq, 0);
                Screen0_RightTurnImageSeq->fn->showImage(Screen0_RightTurnImageSeq, 0);

                rightTurnEnabled = 0;
                leftTurnEnabled = 0;

                idleTickCount = 0;

                APP_ClearScreenEvents();
                
                /* Show all panels after POR boot animation */
                if (screenState == APP_SCREEN_POR_TEST_OK)
                {
                    APP_LE_SETVISIBLE(Screen0_MicrochipLogo, LE_TRUE);
                    APP_LE_SETVISIBLE(Screen0_IndicatorsPanel, LE_TRUE);                       
                    APP_LE_SETVISIBLE(Screen0_MicrochipLogo_0, LE_FALSE);
                    APP_LE_SETVISIBLE(Screen0_TurnModePanel, LE_TRUE);            
                    APP_LE_SETVISIBLE(Screen0_Directions, LE_TRUE);
                    APP_LE_SETVISIBLE(Screen0_RangePanel, LE_TRUE);
                    APP_LE_SETVISIBLE(Screen0_StartButton, LE_TRUE);
                    APP_LE_SETVISIBLE(Screen0_MetricsButton, LE_TRUE);
                    
                    APP_LE_SETVISIBLE(Screen0_MicrochipLogo_0, LE_FALSE);
                    APP_LE_SETVISIBLE(Screen0_MGSLogo, LE_FALSE);
                    
                    screenState = APP_SCREEN_POR_ANIM1;  
                }
                else
                {
                    screenState = APP_SCREEN_IDLE;  
                }
            }

            break;
        }
        /* next stage animation to show the speed and MPH labels */
        case APP_SCREEN_POR_ANIM1:
        {
            if(lastTickCount != tickCount)
            {
                if ((tickCount % ANIM_PERIOD_TICKS) == 0)
                {
                    int32_t x, y, deltax, deltay;
            
                    x = APP_LE_GETX(Screen0_mphLabel);
                    y = APP_LE_GETY(Screen0_SpeedoValueLabel);

                    deltax = (MPH_SHOW_X - x ) / DELTA_EASE_COEFF;
                    deltay = (SPEED_SHOW_Y - y) / DELTA_EASE_COEFF;

                    if (deltax != 0)
                    {
                        APP_LE_SETX(Screen0_mphLabel, x + deltax);
                    }
                    else
                    {
                        APP_LE_SETX(Screen0_mphLabel, MPH_SHOW_X);
                    }

                    if (deltay != 0)
                    {
                        APP_LE_SETY(Screen0_SpeedoValueLabel, y + deltay);
                    }
                    else
                    {
                        APP_LE_SETY(Screen0_SpeedoValueLabel, SPEED_SHOW_Y);
                    }

                    if (deltay == 0 && deltax == 0)
                    {
                        screenState = APP_SCREEN_POR_ANIM2; 
                    }
                }
                
                lastTickCount = tickCount;
            }              
            
            break;
        }
        /* next stage animation to direction arrows/label, range bar/label */
        case APP_SCREEN_POR_ANIM2:
        {
            if(lastTickCount != tickCount)
            {
                if ((tickCount % ANIM_PERIOD_TICKS) == 0)
                {
                    int32_t rangeDelta;
                    int32_t x, y, deltax, deltay;
            
                    y = APP_LE_GETY(Screen0_DirectionArrows);
                    x = APP_LE_GETX(Screen0_DistanceLabel);

                    rangeDelta = (RANGE_VALUE_DEFAULT - rangeValue ) / DELTA_EASE_COEFF;                    
                    deltax = (DIRECTIONS_SHOW_X - x ) / DELTA_EASE_COEFF;
                    deltay = (DIRECTION_ARROWS_SHOW_Y - y) / DELTA_EASE_COEFF;
                    
                    if (rangeDelta != 0)
                    {
                        rangeValue += rangeDelta;
                    }
                    else
                    {
                        rangeValue = RANGE_VALUE_DEFAULT;
                    }
                    
                    appSetRangeLabelValue(rangeValue);
                    appSetRangeBarValue(rangeValue);

                    if (deltax != 0)
                    {
                        APP_LE_SETX(Screen0_DistanceLabel, x + deltax);
                        APP_LE_SETX(Screen0_DirectionLabel, x + deltax);
                    }
                    else
                    {
                        APP_LE_SETX(Screen0_DistanceLabel, DIRECTIONS_SHOW_X);
                        APP_LE_SETX(Screen0_DirectionLabel, DIRECTIONS_SHOW_X);
                    }

                    if (deltay != 0)
                    {
                        APP_LE_SETY(Screen0_DirectionArrows, y + deltay);
                    }
                    else
                    {
                        APP_LE_SETY(Screen0_DirectionArrows, DIRECTION_ARROWS_SHOW_Y);
                    }

                    if (deltay == 0 && deltax == 0 && rangeDelta == 0)
                    {
                        screenState = APP_SCREEN_IDLE; 
                    }                    
                }
                
                lastTickCount = tickCount;
            }
            
            break;
        }
        /* main screen idle state */
        case APP_SCREEN_IDLE:
        {
            if(lastTickCount != tickCount)
            { 
                /* If idle period reached, send event to start demo mode */
                if (idleTickCount > DEMO_IDLE_PERIOD_TICKS)
                {
                    APP_SetScreenEvent(APP_SCREEN_EVT_IDLE_ON);
                }

                /* toggle turn lights if enabled */
                if ((tickCount % TURN_LIGHT_PERIOD_TICKS) == 0)
                {
                    turnLightIndex++;
                    
                    if (leftTurnEnabled == true)
                    {
                        Screen0_LeftTurnImageSeq->fn->showImage(Screen0_LeftTurnImageSeq, turnLightIndex % 2);
                    }
                    
                    if (rightTurnEnabled == true)
                    {
                        Screen0_RightTurnImageSeq->fn->showImage(Screen0_RightTurnImageSeq, turnLightIndex % 2);                        
                    }
                }
                
                /* update gauges to target value */
//                if ((tickCount % ANIM_PERIOD_TICKS) == 0)
                {
                    /* current speed gauge value is less than target */
                    if (gaugeValue < tGaugeValue)
                    {
                        int32_t delta = (tGaugeValue - gaugeValue) / DELTA_EASE_COEFF;
                        
                        if (delta == 0)
                        {
                            gaugeValue += 1;
                        }
                        else
                        {
                            delta = (delta > MAX_DELTA_GAUGE) ? MAX_DELTA_GAUGE : delta;
                            gaugeValue += delta;
                        }
                        
                        appSetGaugeValue(gaugeValue);
                        appSetGaugeLabelValue(gaugeValue);
                        
                    }
                    /* speed gauge value is greater than target */
                    else if (gaugeValue > tGaugeValue)
                    {
                        int32_t delta = (gaugeValue - tGaugeValue) / DELTA_EASE_COEFF;
                        
                        /* gradually decrement gauge to target */
                        if (delta == 0)
                        {
                            gaugeValue -= 1;
                        }
                        else
                        {
                            delta = (delta > MAX_DELTA_GAUGE) ? MAX_DELTA_GAUGE : delta;
                            gaugeValue -= delta;
                        }
                        
                        appSetGaugeValue(gaugeValue);
                        appSetGaugeLabelValue(gaugeValue);
                        
                    }
                    
                    /* tach value is less than target */
                    if (tachoValue < tTachoValue)
                    {
                        int32_t delta = (tTachoValue - tachoValue) / DELTA_EASE_COEFF;
                        
                        /* increment to target */
                        if (delta == 0)
                        {
                            tachoValue += 1;
                        }
                        else
                        {
                            delta = (delta > MAX_DELTA_TACHO) ? MAX_DELTA_TACHO : delta;
                            tachoValue += delta;
                        }
                        
                        appSetTachoValue(tachoValue);
                    }
                    /* tach value is greater than target */
                    else if (tachoValue > tTachoValue)
                    {
                        int32_t delta = (tachoValue - tTachoValue) / DELTA_EASE_COEFF;
                        
                        /* decrement to target */
                        if (delta == 0)
                        {
                            tachoValue -= 1;
                        }
                        else
                        {
                            delta = (delta > MAX_DELTA_TACHO) ? MAX_DELTA_TACHO : delta;
                            tachoValue -= delta;
                        }

                        appSetTachoValue(tachoValue);
                    }                    
                }   

                lastTickCount = tickCount;             
            }
            
            /* Check if demo start or idle timeout events are set */
            if (APP_GetScreenEvent(APP_SCREEN_EVT_DEMO) == true ||
                APP_GetScreenEvent(APP_SCREEN_EVT_IDLE_ON) == true)
            {
                /* toggle demo on string and go to demo state */
#ifdef DEMO_MODE_ENABLED                
                Screen0_StartButton->fn->setScheme(Screen0_StartButton, &EnabledScheme);
                Screen0_StartButton->fn->setString(Screen0_StartButton, (leString*)&string_DemoOn);      
                screenState = APP_SCREEN_START_DEMO;
#endif                
            }
            /* If left turn button is pressed, toggle left turn button */
            else if (APP_GetScreenEvent(APP_SCREEN_EVT_LEFT_TURN))
            {
                leftTurnEnabled = !leftTurnEnabled;

                Screen0_LeftTurnImageSeq->fn->showImage(Screen0_LeftTurnImageSeq, (leftTurnEnabled == true));
            }
            /* if right turn button is pressed, toggle right turn button */
            else if (APP_GetScreenEvent(APP_SCREEN_EVT_RIGHT_TURN))
            {
                rightTurnEnabled = !rightTurnEnabled;

                Screen0_RightTurnImageSeq->fn->showImage(Screen0_RightTurnImageSeq, (rightTurnEnabled == true));
            }
            /* if user activity is detected, reset idle counter */
            else if (APP_GetScreenEvent(APP_SCREEN_EVT_IDLE_OFF) == true)
            {
                idleTickCount = 0;
            }

            APP_ClearScreenEvents();
            
            break;
        }
#ifdef DEMO_MODE_ENABLED        
        /* start demo state, animate the gauges to start value */
        case APP_SCREEN_START_DEMO:
        {
            if(lastTickCount != tickCount)
            {
                if ((tickCount % ANIM_PERIOD_TICKS) == 0)
                {
                    gaugeValue = (gaugeValue >= SPEEDO_INC_POR) ? 
                                 gaugeValue - SPEEDO_INC_POR : 0;

                    appSetGaugeValue(gaugeValue);
                    appSetGaugeLabelValue(gaugeValue);
                    
                    tachoValue = (tachoValue >= TACHO_INC_POR) ? 
                                 tachoValue - TACHO_INC_POR : 0;
                    
                    appSetTachoValue(tachoValue);
                    
                    gearValue = (gearValue >= 1) ? gearValue - 1 : 0;
                        
                    appSetGearValue(gearValue);
                }
                
                lastTickCount = tickCount;
            }            

            if (gaugeValue == 0 && 
                tachoValue == 0 && 
                gearValue == 0)
            {
                Screen0_LeftTurnImageSeq->fn->showImage(Screen0_LeftTurnImageSeq, 0);
                Screen0_RightTurnImageSeq->fn->showImage(Screen0_RightTurnImageSeq, 0);

                rightTurnEnabled = 0;
                leftTurnEnabled = 0;

                idleTickCount = 0;

                APP_ClearScreenEvents();
                
                screenState = APP_SCREEN_DEMO;
            }

            break;
        }
        /* run demo state, animate the gauges up then down, repeat, 
           toggle turn and direction indicators */
        case APP_SCREEN_DEMO:
        {
            if(lastTickCount != tickCount)
            {
                if ((tickCount % TURN_LIGHT_PERIOD_TICKS) == 0)
                {
                    turnLightIndex++;

                    /* toggle turn lights */
                    if (turnLightIndex % 2)
                        Screen0_StartButton->fn->setScheme(Screen0_StartButton, &DisabledScheme);
                    else
                        Screen0_StartButton->fn->setScheme(Screen0_StartButton, &EnabledScheme);
                    
                    if (leftTurnEnabled == true)
                    {
                        Screen0_LeftTurnImageSeq->fn->showImage(Screen0_LeftTurnImageSeq, turnLightIndex % 2);
                    }
                    else
                    {
                        Screen0_LeftTurnImageSeq->fn->showImage(Screen0_LeftTurnImageSeq, 0);
                    }
                    
                    if (rightTurnEnabled == true)
                    {
                        Screen0_RightTurnImageSeq->fn->showImage(Screen0_RightTurnImageSeq, turnLightIndex % 2);                        
                    }
                    else
                    {
                        Screen0_LeftTurnImageSeq->fn->showImage(Screen0_RightTurnImageSeq, 0);
                    }
                    
                    /* Update direction signal and labels */
                    if (leftTurnEnabled == true && rightTurnEnabled == false)
                    {
                        Screen0_DirectionArrows->fn->setImage(Screen0_DirectionArrows, (leImage*)&turn_left);
                        Screen0_DistanceLabel->fn->setString(Screen0_DistanceLabel, (leString*)&string_DistanceStringLeft);
                        Screen0_DirectionLabel->fn->setString(Screen0_DirectionLabel, (leString*)&string_DirectionStringLeft);
                    }
                    else if (leftTurnEnabled == false && rightTurnEnabled == true)
                    {
                        Screen0_DirectionArrows->fn->setImage(Screen0_DirectionArrows, (leImage*)&turn_right);
                        Screen0_DistanceLabel->fn->setString(Screen0_DistanceLabel, (leString*)&string_DistanceStringRight);
                        Screen0_DirectionLabel->fn->setString(Screen0_DirectionLabel, (leString*)&string_DirectionStringRight);
                    }
                    else
                    {
                        Screen0_DirectionArrows->fn->setImage(Screen0_DirectionArrows, (leImage*)&straigh);
                        Screen0_DistanceLabel->fn->setString(Screen0_DistanceLabel, (leString*)&string_DistanceStringContinue);
                        Screen0_DirectionLabel->fn->setString(Screen0_DirectionLabel, (leString*)&string_DirectionStringContinue);
                    }
                }
                
                /* Update/Animate gauges */
                if ((tickCount % ANIM_PERIOD_TICKS) == 0)
                {
                    /* Increment speed gauge to max, then decrement to min, repeat */
                    gaugeValue += inc;

                    if (gaugeValue <= 0)
                    {
                        inc = SPEEDO_INC;
                    }
                    else if (gaugeValue >= MAX_SPEEDO_VALUE)
                    {
                        inc = -SPEEDO_INC;
                        
                        leftTurnEnabled = !rightTurnEnabled;
                    }

                    appSetGaugeValue(gaugeValue);
                    appSetGaugeLabelValue(gaugeValue);

                    /* Increment tacho gauge to max, then decrement to min, repeat */
                    tachoValue += tachoInc;

                    if (tachoValue <= 0)
                    {
                        tachoInc = TACHO_INC;
                    }
                    else if (tachoValue >= MAX_TACHO_VALUE_x100)
                    {
                        tachoInc = -TACHO_INC;
                        
                        if (gearValue < MAX_GEAR_VALUE)
                        {
                            gearValue += 1;
                            
                            appSetGearValue(gearValue);
                        }
                        else
                        {
                            gearValue = 1;

                            rightTurnEnabled = !rightTurnEnabled;                            
                            appSetGearValue(gearValue);
                        }
                    }

                    appSetTachoValue(tachoValue);
                }

                lastTickCount = tickCount;
                    
            }
            
            /* exit demo if stop or idle reset event is received */
            if (APP_GetScreenEvent(APP_SCREEN_EVT_DEMO) == true ||
                APP_GetScreenEvent(APP_SCREEN_EVT_IDLE_OFF) == true)
            {
                Screen0_StartButton->fn->setScheme(Screen0_StartButton, &DisabledScheme);
                Screen0_StartButton->fn->setString(Screen0_StartButton, (leString*)&string_DemoOff);  
                
                idleTickCount = 0;

                screenState = APP_SCREEN_STOP;
            }
            
            APP_ClearScreenEvents();            
    
            break;
        }
#endif        
        default:
            break;
    }
    
    /* Query task metrics every second */
    if (secCount != secCountLast)
    {
        Screen0_UpdateMetrics();
    }
}

/* Screen button event callbacks */
void event_Screen0_StartButton_OnPressed(leButtonWidget* btn)
{
}

/* Start demo on button release */
void event_Screen0_StartButton_OnReleased(leButtonWidget* btn)
{
    APP_SetScreenEvent(APP_SCREEN_EVT_DEMO);
}

/* toggle turn lights on left button press */
void event_Screen0_LeftTurnButton_OnPressed(leButtonWidget* btn)
{
    APP_SetScreenEvent(APP_SCREEN_EVT_LEFT_TURN);
}

/* toggle turn lights on left button release */
void event_Screen0_LeftTurnButton_OnReleased(leButtonWidget* btn)
{
    
    APP_SetScreenEvent(APP_SCREEN_EVT_LEFT_TURN);

}

/* toggle turn lights on right button release */
void event_Screen0_RightTurnButton_OnPressed(leButtonWidget* btn)
{
    APP_SetScreenEvent(APP_SCREEN_EVT_RIGHT_TURN);
}

/* toggle turn lights on right button release */
void event_Screen0_RightTurnButton_OnReleased(leButtonWidget* btn)
{
    APP_SetScreenEvent(APP_SCREEN_EVT_RIGHT_TURN);
}

/* turn on/off task metrics */
void event_Screen0_MetricsButton_OnPressed(leButtonWidget* btn)
{
     APP_LE_SETVISIBLE(Screen0_MetricsLabel, LE_TRUE);
}

void event_Screen0_MetricsButton_OnReleased(leButtonWidget* btn)
{
     APP_LE_SETVISIBLE(Screen0_MetricsLabel, LE_FALSE);
}
