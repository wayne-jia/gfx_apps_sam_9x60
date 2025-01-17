/*******************************************************************************
  Board Support Package Header File.

  Company:
    Microchip Technology Inc.

  File Name:
    bsp.h

  Summary:
    Board Support Package Header File 

  Description:
    This file contains constants, macros, type definitions and function
    declarations 
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

#ifndef _BSP_H
#define _BSP_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "device.h"

// *****************************************************************************
// *****************************************************************************
// Section: BSP Macros
// *****************************************************************************
// *****************************************************************************
/*** LED Macros for LED_BLUE ***/
#define LED_BLUE_Toggle() (PIOB_REGS->PIO_ODSR ^= (1<<13))
#define LED_BLUE_On() (PIOB_REGS->PIO_SODR = (1<<13))
#define LED_BLUE_Off() (PIOB_REGS->PIO_CODR = (1<<13))
/*** LED Macros for LED_GREEN ***/
#define LED_GREEN_Toggle() (PIOB_REGS->PIO_ODSR ^= (1<<12))
#define LED_GREEN_On() (PIOB_REGS->PIO_SODR = (1<<12))
#define LED_GREEN_Off() (PIOB_REGS->PIO_CODR = (1<<12))
/*** LED Macros for LED_RED ***/
#define LED_RED_Toggle() (PIOB_REGS->PIO_ODSR ^= (1<<11))
#define LED_RED_On() (PIOB_REGS->PIO_SODR = (1<<11))
#define LED_RED_Off() (PIOB_REGS->PIO_CODR = (1<<11))
/*** SWITCH Macros for SWITCH_AL_PD18 ***/
#define SWITCH_AL_PD18_Get() ((PIOD_REGS->PIO_PDSR >> 18) & 0x1)
#define SWITCH_AL_PD18_STATE_PRESSED 0
#define SWITCH_AL_PD18_STATE_RELEASED 1
/*** VBUS Macros for VBUS_AH_PD14 ***/
#define VBUS_AH_PD14_PowerEnable() (PIOD_REGS->PIO_SODR = (1<<14))
#define VBUS_AH_PD14_PowerDisable() (PIOD_REGS->PIO_CODR = (1<<14))
/*** VBUS Macros for VBUS_AH_PD16 ***/
#define VBUS_AH_PD16_PowerEnable() (PIOD_REGS->PIO_SODR = (1<<16))
#define VBUS_AH_PD16_PowerDisable() (PIOD_REGS->PIO_CODR = (1<<16))
/*** VBUS Macros for VBUS_AH_PD15 ***/
#define VBUS_AH_PD15_PowerEnable() (PIOD_REGS->PIO_SODR = (1<<15))
#define VBUS_AH_PD15_PowerDisable() (PIOD_REGS->PIO_CODR = (1<<15))




// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void BSP_Initialize(void)

  Summary:
    Performs the necessary actions to initialize a board

  Description:
    This function initializes the LED and Switch ports on the board.  This
    function must be called by the user before using any APIs present on this
    BSP.

  Precondition:
    None.

  Parameters:
    None

  Returns:
    None.

  Example:
    <code>
    //Initialize the BSP
    BSP_Initialize();
    </code>

  Remarks:
    None
*/

void BSP_Initialize(void);

#endif // _BSP_H

/*******************************************************************************
 End of File
*/
