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
 * Name:   bg240
 * Size:   240x240 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage bg240;

/*********************************
 * Legato Image Asset
 * Name:   m
 * Size:   80x80 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage m;

/*********************************
 * Legato Image Asset
 * Name:   b20
 * Size:   135x45 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage b20;

/*********************************
 * Legato Image Asset
 * Name:   b40
 * Size:   135x45 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage b40;

/*********************************
 * Legato Image Asset
 * Name:   b60
 * Size:   135x45 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage b60;

/*********************************
 * Legato Image Asset
 * Name:   b80
 * Size:   135x45 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage b80;

/*********************************
 * Legato Image Asset
 * Name:   b100
 * Size:   135x45 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage b100;

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
 * Range Count:  6
 * Glyph Ranges: 0x20-0x7E
***********************************/
extern leRasterFont NotoSansBoldItalic20;

/*****************************************************************************
 * Legato String Table
 * Encoding        UTF8
 * Language Count: 1
 * String Count:   5
 *****************************************************************************/

// language IDs
#define language_English    0

// string IDs
#define stringID_s20    0
#define stringID_s40    1
#define stringID_s100    2
#define stringID_s80    3
#define stringID_s60    4

extern const leStringTable stringTable;


// string list
extern leTableString string_s20;
extern leTableString string_s40;
extern leTableString string_s100;
extern leTableString string_s80;
extern leTableString string_s60;

void initializeStrings(void);
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* LE_GEN_ASSETS_H */
