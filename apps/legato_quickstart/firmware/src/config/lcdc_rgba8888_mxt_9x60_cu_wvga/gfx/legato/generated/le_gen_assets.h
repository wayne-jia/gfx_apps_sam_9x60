/*******************************************************************************
 Module for Microchip Legato Graphics Library

  Company:
    Microchip Technology Inc.

  File Name:
    le_gen_assets.h

  Summary:
    Header file containing a list of asset specifications for use with the
    Legato Graphics Stack.


  Description:
    Header file containing a list of asset specifications for use with the
    Legato Graphics Stack.

*******************************************************************************/


// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C)  Microchip Technology Inc. and its subsidiaries.
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

#ifndef LE_GEN_ASSETS_H
#define LE_GEN_ASSETS_H

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

#include "gfx/legato/legato.h"

extern const lePalette leGlobalPalette;

/*****************************************************************************
 * Legato Graphics Image Assets
 *****************************************************************************/
/*********************************
 * Legato Image Asset
 * Name:   mchp_circle
 * Size:   80x80 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage mchp_circle;

/*********************************
 * Legato Image Asset
 * Name:   bg240
 * Size:   240x240 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage bg240;

/*********************************
 * Legato Image Asset
 * Name:   bulb_m
 * Size:   40x40 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage bulb_m;

/*********************************
 * Legato Image Asset
 * Name:   clock_m
 * Size:   32x32 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage clock_m;

/*********************************
 * Legato Image Asset
 * Name:   fan_m
 * Size:   32x32 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage fan_m;

/*********************************
 * Legato Image Asset
 * Name:   gear_m
 * Size:   32x32 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage gear_m;

/*********************************
 * Legato Image Asset
 * Name:   home_m
 * Size:   32x32 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage home_m;

/*********************************
 * Legato Image Asset
 * Name:   leaf_m
 * Size:   32x28 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage leaf_m;

/*********************************
 * Legato Image Asset
 * Name:   sound_m
 * Size:   36x28 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage sound_m;

/*********************************
 * Legato Image Asset
 * Name:   thermo_m
 * Size:   24x44 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage thermo_m;

/*****************************************************************************
 * Legato Graphics Font Assets
 *****************************************************************************/
/*********************************
 * Legato Font Asset
 * Name:         NotoSansBoldItalic20
 * Height:       21
 * Baseline:     14
 * Style:        Antialias
 * Glyph Count:  95
 * Range Count:  11
 * Glyph Ranges: 0x20-0x7E
***********************************/
extern leRasterFont NotoSansBoldItalic20;

/*********************************
 * Legato Font Asset
 * Name:         sc22
 * Height:       23
 * Baseline:     21
 * Style:        Antialias
 * Glyph Count:  105
 * Range Count:  11
 * Glyph Ranges: 0x20-0x7E
                 0x4F60
                 0x56DE
                 0x597D
                 0x6469
                 0x6839
                 0x7CFB
                 0x7EDF
                 0x7F6E
                 0x8BBE
                 0x8FD4
***********************************/
extern leRasterFont sc22;

/*****************************************************************************
 * Legato String Table
 * Encoding        UTF8
 * Language Count: 1
 * String Count:   5
 *****************************************************************************/

// language IDs
#define language_English    0

// string IDs
#define stringID_ret    0
#define stringID_set    1
#define stringID_sc    2
#define stringID_Hello    3
#define stringID_Shezhi    4

extern const leStringTable stringTable;


// string list
extern leTableString string_ret;
extern leTableString string_set;
extern leTableString string_sc;
extern leTableString string_Hello;
extern leTableString string_Shezhi;

void initializeStrings(void);
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* LE_GEN_ASSETS_H */
