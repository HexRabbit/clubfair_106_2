#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
int num = 0;

void handler()
{
  exit(0);
}

void init()
{
  setvbuf(stdin,NULL,_IONBF,0);
  setvbuf(stdout,NULL,_IONBF,0);
  signal(SIGALRM, handler);
  alarm(30);
}

void print()
{
  puts("########################");
  puts("#    Broken terminal   #");
  puts("#                      #");
  puts("#  1. write some code  #");
  puts("#  2. view your code   #");
  puts("#  3. execute          #");
  puts("########################");
  printf("$ ");
}

void write_code(char *msg, int index)
{
  read(0, msg+16*index, 0x38);
  /*
   * leak canary: 0x38+0x1
   * leak libc: 0x38
   * stack migration: 0x30 (0x28 + leave)
   */
  printf("You write some code on index %d\n", index);
}

void view_code(char *msg, int index)
{
  printf("The code you've written: %s", msg+16*index);
}

int main()
{
  init();
  int cnt = 0;
  char msg[5][16]; // rbp-0x60
  while(num != 3) {
    print();
    scanf("%d", &num);
    switch(num)
    {
      case 1:
      {
        if(cnt == 5) {
          puts("Code segment is full");
          break;
        }
        write_code((char *)msg, cnt++);
        break;
      }
      case 2:
      {
        int n;
        printf("Which index? ");
        scanf("%d", &n);
        if(n < 5)
          /* could be used to get stack address if PIE is enabled */
          view_code((char *)msg, n);
        else
          puts("Permission denied");
        break;
      }
    }
  }
  return 0;
}
