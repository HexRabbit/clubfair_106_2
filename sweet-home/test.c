#include <stdlib.h>
#include <unistd.h>
int main()
{
  char a[100];
  read(0,a,0x38);
  return 0;
}
