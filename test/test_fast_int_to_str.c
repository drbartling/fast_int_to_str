
#ifdef __XC
#include <xc.h>
#define _HOSTED

void putch(char c)
{

}

#else
uint8_t LATA;
#endif

#include "unity.h"
#include "fast_int_to_str.h"

#define STR_SIZE (30)
static char str[STR_SIZE] = {0};

void setUp(void)
{
    int i;
    for (i = 0; i < STR_SIZE; i++)
    {
        str[i] = 0;
    }
    LATA = 1;
}

void tearDown(void)
{
    LATA = 0;
}

void test_IntToStr(void)
{
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

void test_UintToStr(void)
{
    FAST_UintToStr(str, 0);
    TEST_ASSERT_EQUAL_STRING("0", str);

    // Test extremes
    FAST_UintToStr(str, UINT32_MAX);
    TEST_ASSERT_EQUAL_STRING("4294967295", str);

    //Test random values
    FAST_UintToStr(str, 3394720241U);
    TEST_ASSERT_EQUAL_STRING("3394720241", str);
    FAST_UintToStr(str, 1772734251U);
    TEST_ASSERT_EQUAL_STRING("1772734251", str);
    FAST_UintToStr(str, 2207051211U);
    TEST_ASSERT_EQUAL_STRING("2207051211", str);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_IntToStr);
    RUN_TEST(test_Int8ToStr);
    RUN_TEST(test_Int16ToStr);
    RUN_TEST(test_Int32ToStr);
    RUN_TEST(test_UintToStr);
    RUN_TEST(test_Uint8ToStr);
    RUN_TEST(test_Uint16ToStr);
    RUN_TEST(test_Uint32ToStr);
    return UNITY_END();
}
