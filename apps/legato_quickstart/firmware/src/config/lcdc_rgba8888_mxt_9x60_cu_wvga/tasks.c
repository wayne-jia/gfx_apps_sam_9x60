/*******************************************************************************
 System Tasks File

  File Name:
    tasks.c

  Summary:
    This file contains source code necessary to maintain system's polled tasks.

  Description:
    This file contains source code necessary to maintain system's polled tasks.
    It implements the "SYS_Tasks" function that calls the individual "Tasks"
    functions for all polled MPLAB Harmony modules in the system.

  Remarks:
    This file requires access to the systemObjects global data structure that
    contains the object handles to all MPLAB Harmony module objects executing
    polled in the system.  These handles are passed into the individual module
    "Tasks" functions to identify the instance of the module to maintain.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "configuration.h"
#include "definitions.h"
#include "sys_tasks.h"
#include "task.h"


/* CUSTOM CODE START - Do not modify or remove */
#define SHOW_RTOS_IDLE_TASK 1

enum
{
    XLCD_TASK_ID,
    MAXTOUCH_TASK_ID,
    APP_TASK_ID,
    LEGATO_TASK_ID,    
    SYS_INPUT_TASK_ID,
#ifdef SHOW_RTOS_IDLE_TASK
    IDLE_TASK_ID,
#endif
    MAX_TASK_ID
};

typedef struct
{
    TaskHandle_t handle;
    char * name;
    uint32_t lastCount;
    uint32_t count;
    uint32_t usage;
} APP_TASK_STRUCT_t;


APP_TASK_STRUCT_t tasks[MAX_TASK_ID] = 
{
    [XLCD_TASK_ID] = 
    {
        .name = "XLCD Task",
    },
    [MAXTOUCH_TASK_ID] = 
    {
        .name = "maxTouch Task",
    },
    [LEGATO_TASK_ID] = 
    {
        .name = "GFX Task",
    },
    [SYS_INPUT_TASK_ID] = 
    {
        .name = "Input Task",
    },
    [APP_TASK_ID] = {
        .name = "User APP Task",
    },
#ifdef SHOW_RTOS_IDLE_TASK    
    [IDLE_TASK_ID] = {
        .name = "RTOS IDLE Task",
    },
#endif
};

/* This function gets the CPU cycles used by the main APP task and IDLE task.
   The sum of these will be considered free CPU cycles */
unsigned int FreeTask_Usage(void)
{
    static uint32_t ulLastTotalTime = 0;
    unsigned int i = 0;
    uint32_t ulTotalTime;
    uint32_t pctRunTime;
    TaskStatus_t xTaskDetails;
    uint32_t free_app_usage = 0;

#ifdef SHOW_RTOS_IDLE_TASK        
    tasks[IDLE_TASK_ID].handle = xTaskGetIdleTaskHandle();
#endif    
    
    //gather the new total time
    for (i = 0; i < MAX_TASK_ID; i++)
    {
        // Use the handle to obtain further information about the task.
        vTaskGetInfo( tasks[i].handle,
                      &xTaskDetails,
                      pdTRUE, // Include the high water mark in xTaskDetails.
                      eInvalid ); // Include the task state in xTaskDetails.

        tasks[i].count = xTaskDetails.ulRunTimeCounter;
    }

    ulTotalTime = portGET_RUN_TIME_COUNTER_VALUE(); /* get total time passed in system */
    
    for (i = 0; i < MAX_TASK_ID; i++)
    {
        pctRunTime = (((tasks[i].count - tasks[i].lastCount) * 100)/(ulTotalTime - ulLastTotalTime));
        pctRunTime = (pctRunTime > 100) ? 100 : pctRunTime;
        
        if (pctRunTime > 0)
        {
            tasks[i].usage = pctRunTime;
            
            printf("%.20s \t%u",
                    tasks[i].name,
                    (unsigned int) tasks[i].usage);
        }
        else
        {
            printf("%.20s \t<1",
                    tasks[i].name);
        }
        tasks[i].lastCount = tasks[i].count;
        
        if ((i == APP_TASK_ID) || (i == IDLE_TASK_ID))
        {
            free_app_usage += pctRunTime;
            printf(" (free) \r\n");
        }
        else
        {
            printf(" \r\n");
        }
    }
    
    ulLastTotalTime = ulTotalTime;
    
    return free_app_usage;
            
}

uint32_t tasksGetGFXUsage(void)
{
    return tasks[LEGATO_TASK_ID].usage;
}
/* CUSTOM CODE END */

// *****************************************************************************
// *****************************************************************************
// Section: RTOS "Tasks" Routine
// *****************************************************************************
// *****************************************************************************
void _LEGATO_Tasks(  void *pvParameters  )
{
    while(1)
    {
        Legato_Tasks();
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void _LCDC_Tasks(  void *pvParameters  )
{
    while(1)
    {
        DRV_LCDC_Update();
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void _SYS_INPUT_Tasks(  void *pvParameters  )
{
    while(1)
    {
        SYS_INP_Tasks();
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void _DRV_MAXTOUCH_Tasks(  void *pvParameters  )
{
    while(1)
    {
        DRV_MAXTOUCH_Tasks(sysObj.drvMAXTOUCH);
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

/* Handle for the APP_Tasks. */
TaskHandle_t xAPP_Tasks;

static void lAPP_Tasks(  void *pvParameters  )
{   
    while(true)
    {
        APP_Tasks();
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}




// *****************************************************************************
// *****************************************************************************
// Section: System "Tasks" Routine
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void SYS_Tasks ( void )

  Remarks:
    See prototype in system/common/sys_module.h.
*/
void SYS_Tasks ( void )
{
    /* Maintain system services */
    

    /* Maintain Device Drivers */
        xTaskCreate( _LCDC_Tasks,
        "LCDC_Tasks",
        1024,
        (void*)NULL,
        1,
/* CUSTOM CODE START - Do not modify or remove */
        (TaskHandle_t*)&tasks[XLCD_TASK_ID]
/* CUSTOM CODE END */
    );


    xTaskCreate( _DRV_MAXTOUCH_Tasks,
        "DRV_MAXTOUCH_Tasks",
        1024,
        (void*)NULL,
        1,
/* CUSTOM CODE START - Do not modify or remove */
        (TaskHandle_t*)&tasks[MAXTOUCH_TASK_ID]
/* CUSTOM CODE END */
    );



    /* Maintain Middleware & Other Libraries */
    
    xTaskCreate( _LEGATO_Tasks,
        "LEGATO_Tasks",
        1024,
        (void*)NULL,
        1,
/* CUSTOM CODE START - Do not modify or remove */
        (TaskHandle_t*)&tasks[LEGATO_TASK_ID]
/* CUSTOM CODE END */
    );


    xTaskCreate( _SYS_INPUT_Tasks,
        "SYS_INPUT_Tasks",
        1024,
        (void*)NULL,
        1,
/* CUSTOM CODE START - Do not modify or remove */
        (TaskHandle_t*)&tasks[SYS_INPUT_TASK_ID]
/* CUSTOM CODE END */
    );



    /* Maintain the application's state machine. */
        /* Create OS Thread for APP_Tasks. */
    (void) xTaskCreate((TaskFunction_t) lAPP_Tasks,
                "APP_Tasks",
                1024,
                NULL,
                2,
/* CUSTOM CODE START - Do not modify or remove */
                (TaskHandle_t*)&tasks[APP_TASK_ID]
/* CUSTOM CODE END */
    );




    /* Start RTOS Scheduler. */
    
     /**********************************************************************
     * Create all Threads for APP Tasks before starting FreeRTOS Scheduler *
     ***********************************************************************/
    vTaskStartScheduler(); /* This function never returns. */

}

/*******************************************************************************
 End of File
 */

