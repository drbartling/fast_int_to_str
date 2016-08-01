/*******************************************************************************
 * Fast Integer to String Conversion
 *
 * File Name:
 *  fast_int_to_str.c
 *
 * Summary:
 *  Provides definitions for fast integer to string conversion functions
 *
 * Description:
 *  Provides definitions for fast integer to string conversion functions
 *
 ******************************************************************************/

/*******************************************************************************
MIT License

Copyright (c) 2016 D. Ryan Bartling

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 *******************************************************************************/

//
// Section: Included Files
//

#include "fast_int_to_str.h"
#include <stdbool.h>

#ifndef UINT24_MAX
typedef uint32_t uint24_t;
#define UINT24_MAX (16777215UL)
#endif

typedef union {
    uint32_t u32;
    uint24_t u24;
    uint16_t u16;
    uint8_t u8;
} fast_int_t;

//
// Section: Macros
//

/**
 *
 * @Summary
 *  Used to skip printing leading zeros
 *
 * @Description
 *  Takes a char with a decimal value (0 - 9) and adds it to the string (str) if
 *  it is not a leading zero.
 *
 * @Preconditions
 *  N/A
 *
 * @Params
 *  c - interger from 0 - 9.
 *  str - pointer to a cstring.  Updated and incremented if c is non-zero or
 *        l is false
 *  l - True if still working on leading zeros, false to print 0.  If c is
 *      non 0, this will be set to false.
 *
 * @Returns
 *  str, and l are potentially modified by this macro
 *
 */
#define ConditionalMoveCharToStr(digit, str, leadIn) \
        if (digit || !leadIn) \
        { \
            MoveCharToStr(digit, str); \
            leadIn = false; \
        }

/**
 *
 * @Summary
 *  Takes c and adds it to the string (str)
 *
 * @Description
 *  Takes a value (c) from 0-9, converts it to the corrisponding character
 *  ('0' - '9'), and assigns it to the string.
 *
 * @Preconditions
 *  N/A
 *
 * @Params
 *  c - interger from 0 - 9.
 *  str - pointer to a cstring.
 *
 * @Returns
 *  str, modified by this macro
 *
 */
#define MoveCharToStr(digit, str) \
        *str = digit + '0'; \
        str++

/**
 *
 * @Summary
 *  Gets the leading digit of an integer
 *
 * @Description
 *  Takes a number n, and gets the digit specified by p (place).
 *
 * @Preconditions
 *  n must be less than 10 x p
 *
 * @Params
 *  n - The integer to evaluate
 *  c - a char to store the result
 *  str - pointer to a cstring.
 *
 * @Returns
 *  n - n gets reduced by c * p
 *  c - the digit at place p
 *  p is not modified
 *
 *
 */
#define DigitGet(numberToConvert, digit, orderOfMagnitude) \
        digit = 0; \
        if (numberToConvert >= 8*orderOfMagnitude) \
        { \
            numberToConvert -= 8*orderOfMagnitude; \
            digit = (char) 8; \
        } \
        else \
        { \
            if (numberToConvert >= 4*orderOfMagnitude) \
            { \
                numberToConvert -= 4*orderOfMagnitude; \
                digit = (char) 4; \
            } \
            if (numberToConvert >= 2*orderOfMagnitude) \
            { \
                numberToConvert -= 2*orderOfMagnitude; \
                digit |= (char) 2; \
            } \
        } \
        if (numberToConvert >= 1*orderOfMagnitude) \
        { \
            numberToConvert -= 1*orderOfMagnitude; \
            digit |= (char) 1; \
        }

//
// Section: Template Module APIs
//

void FAST_IntToStr(char str[], int32_t num) {
    if (0 > num) {
        *str = '-';
        str++;
        num = -num;
    }
    FAST_UintToStr(str, num);
}

void FAST_UintToStr(char str[], uint32_t num) {
    fast_int_t fNum;
    fNum.u32 = num;
    char ch = 0;
    bool leedIn = true;

    if (UINT8_MAX >= num) // Check fastest case first
    {
        goto U8;
    } else if (UINT16_MAX >= num) {
        goto U16;
    } else {
        goto U32;
    }

U32:
    if (fNum.u32 >= 4000000000UL) {
        fNum.u32 -= 4000000000UL;
        ch = 4;
    } else {
        if (fNum.u32 >= 2000000000UL) {
            fNum.u32 -= 2000000000UL;
            ch = 2;
        }
        if (fNum.u32 >= 1000000000UL) {
            fNum.u32 -= 1000000000UL;
            ch |= 1;
        }
    }
    ConditionalMoveCharToStr(ch, str, leedIn);

    DigitGet(fNum.u32, ch, 100000000UL);
    ConditionalMoveCharToStr(ch, str, leedIn);

    DigitGet(fNum.u32, ch, 10000000UL);
    ConditionalMoveCharToStr(ch, str, leedIn);

    DigitGet(fNum.u24, ch, 1000000UL);
    ConditionalMoveCharToStr(ch, str, leedIn);

    DigitGet(fNum.u24, ch, 100000UL);
    ConditionalMoveCharToStr(ch, str, leedIn);

U16:
    DigitGet(fNum.u32, ch, 10000UL);
    ConditionalMoveCharToStr(ch, str, leedIn);

    DigitGet(fNum.u16, ch, 1000UL);
    ConditionalMoveCharToStr(ch, str, leedIn);

    DigitGet(fNum.u16, ch, 100UL);
    ConditionalMoveCharToStr(ch, str, leedIn);

U8:
    DigitGet(fNum.u16, ch, 10UL);
    ConditionalMoveCharToStr(ch, str, leedIn);

    DigitGet(fNum.u8, ch, 1UL);
    MoveCharToStr(ch, str);

    *str = 0;
}

char FAST_hexChars[] = "0123456789ABCDEF";

void FAST_UintToHex(char str[], uint32_t num) {
    *str++ = '0';
    *str++ = 'x';
    bool leadIn = true;
    int8_t i;
    for (i = sizeof (num) - 1; i > -1; i--) {
        uint8_t byteToConvert = num >> (i * 8);
        if (0 == byteToConvert) {
            continue;
        }
        uint8_t topNibble = byteToConvert >> 4;
        uint8_t bottomNibble = byteToConvert & 0xF;
        if (!leadIn || topNibble) {
            *str++ = FAST_hexChars[topNibble];
            leadIn = false;
        }
        if (!leadIn || bottomNibble) {
            *str++ = FAST_hexChars[bottomNibble];
            leadIn = false;
        }
    }
    if (leadIn) {
        *str++ = '0';
    }
    *str = 0;
}
