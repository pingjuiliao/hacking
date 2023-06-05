#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char** argv) {

  char* msg = "secret";
  FILE* fp;
  char *buf = malloc(100);
  read(0, buf, 100);
  fp = fopen("key.txt", "rw");
  fp->_flags &= ~8;
  fp->_flags |= 0x800;
  fp->_flags |= 0x1000; // IO_IS_APPENDING
  fp->_IO_write_base = msg;
  fp->_IO_write_ptr = msg + 6;
  fp->_IO_read_end = fp->_IO_write_base;
  fp->_fileno = 1;
  fwrite(buf, 1, 100, fp);
  return 0;
}
