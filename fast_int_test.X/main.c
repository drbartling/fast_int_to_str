/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 3.15.0
        Device            :  PIC16F1619
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20
 */

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
 */

#include "mcc_generated_files/mcc.h"
#include <string.h>
#include <assert.h>
#include "fast_int_to_str.h"

#define TEST_ASSERT_EQUAL_STRING(a,b) TEST_AssertEqualString(a, b, __LINE__)
#define TEST_RUN(a) TEST_SetUp(); a(); TEST_TearDown()
#define STRING_LENGTH (30)

static uint16_t testLength[30] = {0};
static uint8_t testCount = 0;
static char str[STRING_LENGTH] = {0};
static volatile int line;

void TEST_SetUp(void) {
    TMR1_StopTimer();
    TMR1_WriteTimer(0);
    TMR1_StartTimer();
    TEST_PIN_SetHigh();
}

void TEST_TearDown(void) {
    TEST_PIN_SetLow();
    testLength[testCount] = TMR1_ReadTimer();
    testCount++;
}

void TEST_AssertEqualString(const char a[], const char b[], int _line) {
    // If break point gets triggered, look at line or _line to get the line
    // number that failed.
    line = _line;
    __conditional_software_breakpoint(0 == strcmp(a, b));
    NOP();
}

void test_IntToStr(void) {
    // Test 0
    FAST_IntToStr(str, 0);
    TEST_ASSERT_EQUAL_STRING("0", str);

    // Test extremes
    FAST_IntToStr(str, INT32_MAX);
    TEST_ASSERT_EQUAL_STRING("2147483647", str);
    FAST_IntToStr(str, INT32_MIN);
    TEST_ASSERT_EQUAL_STRING("-2147483648", str);

    //Test random values
    FAST_IntToStr(str, 2136747880);
    TEST_ASSERT_EQUAL_STRING("2136747880", str);
    FAST_IntToStr(str, -843995915);
    TEST_ASSERT_EQUAL_STRING("-843995915", str);
    FAST_IntToStr(str, 1203769780);
    TEST_ASSERT_EQUAL_STRING("1203769780", str);
}

void test_UintToStr_Uint8PerfTest(void) {
    FAST_UintToStr(str, UINT8_MAX);
}

void test_UintToStr_Uint16PerfTest(void) {
    FAST_UintToStr(str, UINT16_MAX);
}

void test_UintToStr_Uint32PerfTest(void) {
    FAST_UintToStr(str, UINT32_MAX);
}

void test_IntToStr_Int8PerfTest(void) {
    FAST_IntToStr(str, INT8_MIN);
}

void test_IntToStr_Int16PerfTest(void) {
    FAST_IntToStr(str, INT16_MIN);
}

void test_IntToStr_Int32PerfTest(void) {
    FAST_IntToStr(str, INT32_MIN);
}

void test_sprintf_Int32PerfTest(void) {
    sprintf(str, "%ld", INT32_MIN);
}

/*
                         Main application
 */
void main(void) {
    // initialize the device
    SYSTEM_Initialize();

    TEST_RUN(test_IntToStr);
    TEST_RUN(test_UintToStr_Uint8PerfTest);
    TEST_RUN(test_UintToStr_Uint16PerfTest);
    TEST_RUN(test_UintToStr_Uint32PerfTest);
    TEST_RUN(test_IntToStr_Int8PerfTest);
    TEST_RUN(test_IntToStr_Int16PerfTest);
    TEST_RUN(test_IntToStr_Int32PerfTest);
    TEST_RUN(test_sprintf_Int32PerfTest);

    while (1) {
        __builtin_software_breakpoint();
    }

    return;
}
/**
 End of File
 */