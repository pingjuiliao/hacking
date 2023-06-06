#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

char* hello = "hellllo\n";
int
main(int argc, char** argv) {
  void* region = mmap(NULL, 0x1000, PROT_WRITE, MAP_ANONYMOUS|MAP_PRIVATE, 0, 0);
  strcpy((char *)region, hello);

  munmap(region, 0x1000);
  write(1, region, 0x10);
  return 0;
}
