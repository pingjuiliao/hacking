#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char** argv) {
  int ret = msync(0x8048000, 0x1000, 0);
  printf("%d\n", ret);
  ret = msync(0xdddd0000, 0x1000, 0);
  printf("%d\n", ret);
  return 0;
}
