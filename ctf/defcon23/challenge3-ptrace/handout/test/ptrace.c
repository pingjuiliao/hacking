#include <stdio.h>
#include <sys/ptrace.h>

int
main(int argc, char** argv) {
  enum __ptrace_request req = PTRACE_GETREGS;
  printf("%p\n",req);
  ptrace(req,getpid(), 0,0);

  return 0;
}
