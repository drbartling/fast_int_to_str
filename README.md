# fast_int_to_str
Does what it says on the tin.  printf() was taking too long so I wrote this.

Target is small 8-bit micros, like PIC or AVR.  On XC8, it is about ~~20x~~ make that ~30x faster than printf(), as demonstrated in the screenshot below.

sprintf takes a bit shy of 3 ms for to convert INT32_MIN.  FAST_IntToStr takes just under 100uS.

Function list:

void FAST_IntToStr(char *str int32_t num);

void FAST_UintToStr(char *str uint32_t num);
