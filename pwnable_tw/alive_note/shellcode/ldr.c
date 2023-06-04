#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void (*shellcode)() = NULL;

void check_shellcode() {

}

void run_shellcode() {
  (*shellcode)();
}

int
main(int argc, char** argv) {
  int fd = open("./shellcode.bin", O_RDONLY);
  shellcode = mmap(NULL, 0x1000, PROT_EXEC|PROT_WRITE|PROT_READ, 
                   MAP_ANONYMOUS|MAP_PRIVATE, 0, 0);
  bzero(shellcode, 0x1000);
  int r = read(fd, shellcode, 0x100);
  if (r <= 0) {
    fprintf(stderr, "read error\n");
    exit(-1);
  } 
  close(fd);
  printf("shellcode: %p\n", shellcode);
  printf("shellcode: %s\n", (char *)shellcode);
  check_shellcode();
  run_shellcode();
  return 0;
}
