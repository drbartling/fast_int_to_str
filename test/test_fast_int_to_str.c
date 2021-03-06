
#include "unity.h"
#include "fast_int_to_str.h"

#define STR_SIZE (30)
static char str[STR_SIZE] = {0};

void setUp(void) {
    int i;
    for (i = 0; i < STR_SIZE; i++) {
        str[i] = 0;
    }
}

void tearDown(void) {
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

void test_UintToStr(void) {
    FAST_UintToStr(str, 0U);
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

void test_UintToHex(void) {
    FAST_UintToHex(str, 0U);
    TEST_ASSERT_EQUAL_STRING("0x0", str);

    // Test extremes
    FAST_UintToHex(str, UINT32_MAX);
    TEST_ASSERT_EQUAL_STRING("0xFFFFFFFF", str);

    //Test random values
    FAST_UintToHex(str, 0xABF81540);
    TEST_ASSERT_EQUAL_STRING("0xABF81540", str);
    FAST_UintToHex(str, 0x102C7362);
    TEST_ASSERT_EQUAL_STRING("0x102C7362", str);
    FAST_UintToHex(str, 0xECAC51A);
    TEST_ASSERT_EQUAL_STRING("0xECAC51A", str);
    FAST_UintToHex(str, 0x7D685C);
    TEST_ASSERT_EQUAL_STRING("0x7D685C", str);
    FAST_UintToHex(str, 0xD685C);
    TEST_ASSERT_EQUAL_STRING("0xD685C", str);
    FAST_UintToHex(str, 0x6581);
    TEST_ASSERT_EQUAL_STRING("0x6581", str);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_IntToStr);
    RUN_TEST(test_UintToStr);
    RUN_TEST(test_UintToHex);
    return UNITY_END();
}
