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

const uint8_t stringTable_data[86] =
{
    0x05,0x00,0x01,0x00,0x01,0x18,0x00,0x00,0x00,0x20,0x00,0x00,0x01,0x2A,0x00,0x00,
    0x00,0x38,0x00,0x00,0x01,0x48,0x00,0x00,0x06,0x00,0xE8,0xBF,0x94,0xE5,0x9B,0x9E,
    0x08,0x00,0x53,0x65,0x74,0x74,0x69,0x6E,0x67,0x73,0x0C,0x00,0xE4,0xBD,0xA0,0xE5,
    0xA5,0xBD,0xE6,0x91,0xA9,0xE6,0xA0,0xB9,0x0D,0x00,0x48,0x65,0x6C,0x6C,0x6F,0x20,
    0x4D,0x6F,0x6F,0x72,0x67,0x65,0x6E,0x00,0x0C,0x00,0xE7,0xB3,0xBB,0xE7,0xBB,0x9F,
    0xE8,0xAE,0xBE,0xE7,0xBD,0xAE,
};

/* font asset pointer list */
leFont* fontList[2] =
{
    (leFont*)&NotoSansBoldItalic20,
    (leFont*)&sc22,
};

const leStringTable stringTable =
{
    {
        LE_STREAM_LOCATION_ID_INTERNAL, // data location id
        (void*)stringTable_data, // data address pointer
        86, // data size
    },
    (void*)stringTable_data, // string table data
    fontList, // font lookup table
    LE_STRING_ENCODING_UTF8 // encoding standard
};


// string list
leTableString string_ret;
leTableString string_set;
leTableString string_sc;
leTableString string_Hello;
leTableString string_Shezhi;

void initializeStrings(void)
{
    leTableString_Constructor(&string_ret, stringID_ret);
    leTableString_Constructor(&string_set, stringID_set);
    leTableString_Constructor(&string_sc, stringID_sc);
    leTableString_Constructor(&string_Hello, stringID_Hello);
    leTableString_Constructor(&string_Shezhi, stringID_Shezhi);
}
