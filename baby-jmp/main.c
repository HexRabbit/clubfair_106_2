#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler()
{
  exit(0);
}

void vuln()
{
  puts("warp to earth!");
  system("/bin/cat /home/baby-jmp/flag");
}


void story()
{
  signal(SIGALRM, handler);
  alarm(10);
  setvbuf(stdout,NULL,_IONBF,1024);
  char lastword[20];
  puts("You're in a spaceship, but somehow the engine is broken, and you're dying,");
  puts("the only one way to escape is to open a wormhole to the earth,");
  printf("you roughly remember that the address of earth is: %p\n", &vuln);
  puts("");
  printf("So, input the coordinate to the wardrive engine: ");
  read(0,lastword,0x30);
}

int main()
{
  story();
  puts("Spaceship has exploded, no one survived");
  return 0;
}
