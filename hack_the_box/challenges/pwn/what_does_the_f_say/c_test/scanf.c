#include <stdio.h>
#include <unistd.h>
int
main(int argc, char** argv) {
  unsigned char buf[10];
  scanf("%s", buf);
  for (int i = 0; i < 10; ++i) {
    printf("buf[%d] %c\n", i, buf[i]);
  }
  return 0;
}
