#include <stdio.h>
#include <stdlib.h>
#define INTERNAL_SIZE_T size_t
#define MINSIZE (unsigned long)((((__builtin_offsetof(struct malloc_chunk, fd_nextsize))+((2 * (sizeof (size_t)) < __alignof__ (long double) ? __alignof__ (long double) : 2 * (sizeof (size_t))) - 1)) & ~((2 * (sizeof (size_t)) < __alignof__ (long double) ? __alignof__ (long double) : 2 * (sizeof (size_t))) - 1)))

struct malloc_chunk {
  INTERNAL_SIZE_T      mchunk_prev_size;  /* Size of previous chunk (if free).  */
  INTERNAL_SIZE_T      mchunk_size;       /* Size in bytes, including overhead. */
  struct malloc_chunk* fd;                /* double links -- used only if free. */
  struct malloc_chunk* bk;
  /* Only used for large blocks: pointer to next larger size.  */
  struct malloc_chunk* fd_nextsize; /* double links -- used only if free. */
  struct malloc_chunk* bk_nextsize;
};

int main()
{
  printf("%u\n", (unsigned)MINSIZE);
  char *s = malloc(8);
  for(int i=0; i<7; ++i) {
    s[i] = 'A';
  }
  int nb;
  scanf("%d", &nb);
  if ((unsigned long) (315) >= (unsigned long) (nb + MINSIZE)) {
    s = malloc(nb);
    printf("%s", s);
  }
  return 0;
}
