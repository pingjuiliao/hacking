
#include <linux/seccomp.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/prctl.h>
#include <unistd.h>

int
main(int argc, char** argv) {
  prctl(PR_SET_SECCOMP, SECCOMP_MODE_STRICT);
  return 0;
}
