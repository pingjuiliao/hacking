#include <stdio.h>
#include <stdlib.h>
int
main(int argc, char** argv) {
  if (argc < 2)
    exit(-1);
  int r = printf(argv[1]);
  printf("%d\n", r);
  return 0;
}
