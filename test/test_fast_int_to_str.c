
#include "unity.h"
#include "fast_int_to_str.h"

#define STR_SIZE (30)
static char str[STR_SIZE] = {0};

void setUp(void){
    int i;
    for(i = 0; i < STR_SIZE; i++)
    {
        str[i] = 0;
    }
}

void tearDown(void){
    
}

void test_IntToStr(void)
{
    // Test 0
    FAST_IntToStr(str, 0);
    TEST_ASSERT_EQUAL_STRING("0", str);
    
    // Test extreems
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

void test_Int8ToStr(void)
{
    // Test 0
    FAST_Int8ToStr(str, 0);
    TEST_ASSERT_EQUAL_STRING("0", str);
    
    // Test extreems
    FAST_Int8ToStr(str, INT8_MAX);
    TEST_ASSERT_EQUAL_STRING("127", str);
    FAST_Int8ToStr(str, INT8_MIN);
    TEST_ASSERT_EQUAL_STRING("-128", str);
    
    //Test random values
    FAST_Int8ToStr(str, 66);
    TEST_ASSERT_EQUAL_STRING("66", str);
    FAST_Int8ToStr(str, -32);
    TEST_ASSERT_EQUAL_STRING("-32", str);
    FAST_Int8ToStr(str, -103);
    TEST_ASSERT_EQUAL_STRING("-103", str);
}

void test_Int16ToStr(void)
{
    // Test 0
    FAST_Int16ToStr(str, 0);
    TEST_ASSERT_EQUAL_STRING("0", str);
    
    // Test extreems
    FAST_Int16ToStr(str, INT16_MAX);
    TEST_ASSERT_EQUAL_STRING("32767", str);
    FAST_Int16ToStr(str, INT16_MIN);
    TEST_ASSERT_EQUAL_STRING("-32768", str);
    
    //Test random values
    FAST_Int16ToStr(str, 14276);
    TEST_ASSERT_EQUAL_STRING("14276", str);
    FAST_Int16ToStr(str, -16589);
    TEST_ASSERT_EQUAL_STRING("-16589", str);
    FAST_Int16ToStr(str, -16324);
    TEST_ASSERT_EQUAL_STRING("-16324", str);

}

void test_Int32ToStr(void)
{
    // Test 0
    FAST_Int32ToStr(str, 0);
    TEST_ASSERT_EQUAL_STRING("0", str);
    
    // Test extreems
    FAST_Int32ToStr(str, INT16_MAX);
    TEST_ASSERT_EQUAL_STRING("32767", str);
    FAST_Int32ToStr(str, INT16_MIN);
    TEST_ASSERT_EQUAL_STRING("-32768", str);
    
    //Test random values
    FAST_Int32ToStr(str, 1810559186);
    TEST_ASSERT_EQUAL_STRING("1810559186", str);
    FAST_Int32ToStr(str, -1914293320);
    TEST_ASSERT_EQUAL_STRING("-1914293320", str);
    FAST_Int32ToStr(str, 2110284714);
    TEST_ASSERT_EQUAL_STRING("2110284714", str);
}

void test_UintToStr(void)
{
    FAST_UintToStr(str, 0);
    TEST_ASSERT_EQUAL_STRING("0", str);
    
    // Test extreems
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

void test_Uint8ToStr(void)
{
    FAST_Uint8ToStr(str, 0);
    TEST_ASSERT_EQUAL_STRING("0", str);
    
    // Test extreems
    FAST_Uint8ToStr(str, UINT8_MAX);
    TEST_ASSERT_EQUAL_STRING("255", str);
    
    //Test random values
    FAST_Uint8ToStr(str, 1U);
    TEST_ASSERT_EQUAL_STRING("1", str);
    FAST_Uint8ToStr(str, 58U);
    TEST_ASSERT_EQUAL_STRING("58", str);
    FAST_Uint8ToStr(str, 246U);
    TEST_ASSERT_EQUAL_STRING("246", str);
}

void test_Uint16ToStr(void)
{
    FAST_Uint16ToStr(str, 0);
    TEST_ASSERT_EQUAL_STRING("0", str);
    
    // Test extreems
    FAST_Uint16ToStr(str, UINT16_MAX);
    TEST_ASSERT_EQUAL_STRING("65535", str);
    
    //Test random values
    FAST_Uint16ToStr(str, 1373U);
    TEST_ASSERT_EQUAL_STRING("1373", str);
    FAST_Uint16ToStr(str, 46906U);
    TEST_ASSERT_EQUAL_STRING("46906", str);
    FAST_Uint16ToStr(str, 62017U);
    TEST_ASSERT_EQUAL_STRING("62017", str);
}

void test_Uint32ToStr(void)
{
    FAST_Uint32ToStr(str, 0);
    TEST_ASSERT_EQUAL_STRING("0", str);
    
    // Test extreems
    FAST_Uint32ToStr(str, UINT32_MAX);
    TEST_ASSERT_EQUAL_STRING("4294967295", str);
    
    //Test random values
    FAST_Uint32ToStr(str, 3890403402U);
    TEST_ASSERT_EQUAL_STRING("3890403402", str);
    FAST_Uint32ToStr(str, 612494264U);
    TEST_ASSERT_EQUAL_STRING("612494264", str);
    FAST_Uint32ToStr(str, 4052344682U);
    TEST_ASSERT_EQUAL_STRING("4052344682", str);
}

int main(void) {
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
