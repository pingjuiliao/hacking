
#include <linux/seccomp.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/prctl.h>
#include <unistd.h>

int
main(int argc, char** argv) {
  for (int page = 0x60000000; page < 0xf7000000; page += 0x1000) {
    if (access(page, 0) == "HTB{") {
      write(1, page, XX);
    }
  }
  
  return 0;
}
