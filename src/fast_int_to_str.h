/*******************************************************************************
 * Fast Integer to String Conversion
 *
 * File Name:
 *  fast_int_to_str.h
 *
 * Summary:
 *  Provides API for fast integer to string conversion functions
 *
 * Description:
 *  Provides API for fast integer to string conversion functions
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

#ifndef FAST_INT_TO_STR_H    // Guards against multiple inclusion
#define FAST_INT_TO_STR_H

//
// Section: Included Files
//

#include <stdint.h>

/**
 *
 * @Summary
 *  These functions convert an integer to a string
 *
 * @Description
 *  These functions convert an integer of a the type in the function to a
 *  string.  There is also a generic signed int function and generic unsigned
 *  int function provided for ease of use / readability at a small speed
 *  penalty.
 *
 * @Preconditions
 *  The pointer provided must be point to a character array large enough to
 *  store the result.
 *
 *  type        array size
 *  int32_t     13
 *  uint32_t    12
 *  int16_t     7
 *  uint16_t    6
 *  int8_t      5
 *  uint8_t     4
 *
 * @Params
 *  *str - pointer to a cstring where the result will be stored
 *  num - integer to convert to string
 *
 * @Returns
 *  Returns result to *str
 *
 * @Comment
 *  None
 *
 * @Example
 *   <code>
 *      char str[12];
 *      FAST_Uint32ToStr(str, currentTime_ms);
 *      printf("%s, ", str);
 *   </code>
 *
 * @See Also
 *  None
 *  
 */
void FAST_IntToStr(char str[], int32_t num);
void FAST_Int8ToStr(char str[], int8_t num);
void FAST_Int16ToStr(char str[], int16_t num);
void FAST_Int32ToStr(char str[], int32_t num);
void FAST_UintToStr(char str[], uint32_t num);
void FAST_Uint8ToStr(char str[], uint8_t num);
void FAST_Uint16ToStr(char str[], uint16_t num);
void FAST_Uint32ToStr(char str[], uint32_t num);

#endif // FAST_INT_TO_STR_H

//
// End of File
//
 
