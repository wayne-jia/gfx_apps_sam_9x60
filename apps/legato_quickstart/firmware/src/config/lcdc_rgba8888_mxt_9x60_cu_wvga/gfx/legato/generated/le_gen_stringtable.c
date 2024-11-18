#include "gfx/legato/generated/le_gen_assets.h"

/*****************************************************************************
 * Legato String Table
 * Encoding        UTF8
 * Language Count: 1
 * String Count:   5
 *****************************************************************************/

/*****************************************************************************
 * string table data
 * 
 * this table contains the raw character data for each string
 * 
 * unsigned short - number of indices in the table
 * unsigned short - number of languages in the table
 * 
 * index array (size = number of indices * number of languages
 * 
 * for each index in the array:
 *   unsigned byte - the font ID for the index
 *   unsigned byte[3] - the offset of the string codepoint data in
 *                      the table
 * 
 * string data is found by jumping to the index offset from the start
 * of the table
 * 
 * string data entry:
 *     unsigned short - length of the string in bytes (encoding dependent)
 *     codepoint data - the string data
 ****************************************************************************/

const uint8_t stringTable_data[54] =
{
    0x05,0x00,0x01,0x00,0x00,0x18,0x00,0x00,0x00,0x1E,0x00,0x00,0x00,0x24,0x00,0x00,
    0x00,0x2A,0x00,0x00,0x00,0x30,0x00,0x00,0x03,0x00,0x32,0x30,0x25,0x00,0x03,0x00,
    0x34,0x30,0x25,0x00,0x04,0x00,0x31,0x30,0x30,0x25,0x03,0x00,0x38,0x30,0x25,0x00,
    0x03,0x00,0x36,0x30,0x25,0x00,
};

/* font asset pointer list */
leFont* fontList[1] =
{
    (leFont*)&NotoSansBoldItalic20,
};

const leStringTable stringTable =
{
    {
        LE_STREAM_LOCATION_ID_INTERNAL, // data location id
        (void*)stringTable_data, // data address pointer
        54, // data size
    },
    (void*)stringTable_data, // string table data
    fontList, // font lookup table
    LE_STRING_ENCODING_UTF8 // encoding standard
};


// string list
leTableString string_s20;
leTableString string_s40;
leTableString string_s100;
leTableString string_s80;
leTableString string_s60;

void initializeStrings(void)
{
    leTableString_Constructor(&string_s20, stringID_s20);
    leTableString_Constructor(&string_s40, stringID_s40);
    leTableString_Constructor(&string_s100, stringID_s100);
    leTableString_Constructor(&string_s80, stringID_s80);
    leTableString_Constructor(&string_s60, stringID_s60);
}
