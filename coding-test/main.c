#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
const char sh[] = "/bin/sh";
char sc[30];

void handler()
{
  exit(0);
}

void failed()
{
  puts("You failed to start emergency isolation system, suffocated to death.");
  exit(0);
}

int main()
{
  signal(SIGALRM, handler);
  signal(SIGSEGV, failed);
  signal(SIGILL, failed);
  alarm(30);
  setvbuf(stdout,NULL,_IONBF,1024);
  puts("You warped to the Earth, but there's still a problem...");
  puts("Because of warping, cabin boor has been distorted into a weird shape, and O2 is leaking");
  puts("");
  puts("To save your life, you need to enable emergency isolation system");
  puts("by input emergency repair code with verfication key");
  printf("Here's the index of the key: %p\n", &sh);
  puts("");
  printf("Now enter your command(length<=20): ");
  read(0,sc,20);
  ((void (*)())sc)();
  return 0;
}
