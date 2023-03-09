#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char** argv) {
  size_t *a, *b, *c;
  size_t target = 1337;
  printf("target: %u\n", target);
  a = (char *)malloc(0x428);
  malloc(0x18);
  b = (char *)malloc(0x418);
  malloc(0x18);
  free(a);
  c = (char *)malloc(0x438);
  free(b);
  a[3] = (size_t)((&target) - 4);

  malloc(0x438);
  printf("target: %u\n", target);
  

  return 0;
}
