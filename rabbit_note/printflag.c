#include <stdio.h>
int main()
{
  unsigned int ch[] = {
    0x8de3fdac,
    0xbd9eda94,
    0x819edadf,
    0xeac38f8d,
    0xbdf2c79d,
    0x819edadf,
    0xbcf2c78d,
    0xb09c8a9d,
    0xb0988fb0,
    0xe9f289c8,
    0x819a8a87,
    0xbadf8a87,
    0xe89cccb0,
    0xa3928987,
    0xdeadbeef
  };
  for(int i=0; i<sizeof(ch)/4; ++i) {
    ch[i] ^= 0xDEADBEEF;
  }
  printf("%s\n", (char *)ch);
  return 0;
}
