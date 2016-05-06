# fast_int_to_str
Does what it says on the tin.  printf() was taking too long so I wrote this.

Target is small 8-bit micros, like PIC or AVR.
On XC8, it is about 20x faster than printf().

Function list:
void FAST_IntToStr(char *str int32_t num);
void FAST_Int8ToStr(char *str, int8_t num);
void FAST_Int16ToStr(char *str, int16_t num);
void FAST_Int32ToStr(char *str, int32_t num);
void FAST_UintToStr(char *str uint32_t num);
void FAST_Uint8ToStr(char *str, uint8_t num);
void FAST_Uint16ToStr(char *str, uint16_t num);
void FAST_Uint32ToStr(char *str, uint32_t num);
