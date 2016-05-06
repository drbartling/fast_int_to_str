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
#define ConditionalMoveCharToStr(c, str, l) \
        if (c || !l) \
        { \
            MoveCharToStr(c, str); \
            l = false; \
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
#define MoveCharToStr(c, str) \
        *str = c + '0'; \
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
#define DigitGet(n, c, p) \
        c = 0; \
        if (n >= 8*p) \
        { \
            n -= 8*p; \
            c = (char) 8; \
        } \
        else \
        { \
            if (n >= 4*p) \
            { \
                n -= 4*p; \
                c = (char) 4; \
            } \
            if (n >= 2*p) \
            { \
                n -= 2*p; \
                c |= (char) 2; \
            } \
        } \
        if (n >= 1*p) \
        { \
            n -= 1*p; \
            c |= (char) 1; \
        }
        
//
// Section: Template Module APIs
//
        
void FAST_IntToStr(char *str, int32_t num)
{
    if (0 > num)
    {
        *str = '-';
        str++;
        num = -num;
    }
    FAST_UintToStr(str, num);
}

void FAST_Int8ToStr(char *str, int8_t num)
{
    if (0 > num)
    {
        *str = '-';
        str++;
        num = -num;
    }
    FAST_Uint8ToStr(str, num);
}

void FAST_Int16ToStr(char *str, int16_t num)
{
    if (0 > num)
    {
        *str = '-';
        str++;
        num = -num;
    }
    FAST_Uint16ToStr(str, num);
}

void FAST_Int32ToStr(char *str, int32_t num)
{
    if (0 > num)
    {
        *str = '-';
        str++;
        num = -num;
    }
    FAST_Uint32ToStr(str, num);
}

void FAST_UintToStr(char *str, uint32_t num)
{
    if(UINT8_MAX >= num) // Check fastest case first
    {
        FAST_Uint8ToStr(str, num);
    }
    else if(UINT16_MAX >= num)
    {
        FAST_Uint16ToStr(str, num);
    }
    else
    {
        FAST_Uint32ToStr(str, num);
    }
}

void FAST_Uint8ToStr(char *str, uint8_t num)
{
    char ch = 0;
    bool leedIn = true;

    // hundreds place
    if (num >= 200)
    {
        ch = 2;
        num -= 200;
    }
    else if (num >= 100)
    {
        ch = 1;
        num -= 100;
    }
    ConditionalMoveCharToStr(ch, str, leedIn);

    // tens place
    DigitGet(num, ch, 10);
    ConditionalMoveCharToStr(ch, str, leedIn);

    // ones place
    DigitGet(num, ch, 1)
    MoveCharToStr(ch, str);

    *str = 0;
}

void FAST_Uint16ToStr(char *str, uint16_t num)
{
    char ch = 0;
    bool leedIn = true;

    // ten-thousands
    if (num >= 40000U)
    {
        num -= 40000U;
        ch = 4;
    }
    if (num >= 20000U)
    {
        num -= 20000U;
        ch |= 2;
    }
    if (num >= 10000U)
    {
        num -= 10000U;
        ch |= 1;
    }
    ConditionalMoveCharToStr(ch, str, leedIn);

    // thousands place
    DigitGet(num, ch, 1000);
    ConditionalMoveCharToStr(ch, str, leedIn);

    // hundreds place
    DigitGet(num, ch, 100);
    ConditionalMoveCharToStr(ch, str, leedIn);

    // tens place
    DigitGet(num, ch, 10);
    ConditionalMoveCharToStr(ch, str, leedIn);

    // ones place
    DigitGet(num, ch, 1)
    MoveCharToStr(ch, str);

    *str = 0;
}

void FAST_Uint32ToStr(char *str, uint32_t num)
{
    char ch = 0;
    bool leedIn = true;

    if (num >= 4000000000L)
    {
        num -= 4000000000L;
        ch = 4;
    }
    else
    {
        if (num >= 2000000000L)
        {
            num -= 2000000000L;
            ch = 2;
        }
        if (num >= 1000000000L)
        {
            num -= 1000000000L;
            ch |= 1;
        }
    }
    ConditionalMoveCharToStr(ch, str, leedIn);

    DigitGet(num, ch, 100000000L);
    ConditionalMoveCharToStr(ch, str, leedIn);

    DigitGet(num, ch, 10000000L);
    ConditionalMoveCharToStr(ch, str, leedIn);

    DigitGet(num, ch, 1000000L);
    ConditionalMoveCharToStr(ch, str, leedIn);

    DigitGet(num, ch, 100000L);
    ConditionalMoveCharToStr(ch, str, leedIn);

    DigitGet(num, ch, 10000L);
    ConditionalMoveCharToStr(ch, str, leedIn);

    DigitGet(num, ch, 1000L);
    ConditionalMoveCharToStr(ch, str, leedIn);

    DigitGet(num, ch, 100L);
    ConditionalMoveCharToStr(ch, str, leedIn);

    DigitGet(num, ch, 10L);
    ConditionalMoveCharToStr(ch, str, leedIn);

    DigitGet(num, ch, 1L);
    MoveCharToStr(ch, str);

    *str = 0;
}

