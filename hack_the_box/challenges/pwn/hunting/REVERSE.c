
// func_1460()
void
main(int argc, char** argv) {
  func_1240();
  void* mapped_addr = func_13d0();

  mapped_addr = mmap(mapped_addr, R|W);
  shellcode = mmap(..);
  ((void(*)() *)shellcode)();
}

void*
func_13d0() {
  char buf[8];
  int fd = open("/dev/urandom", O_RDONLY);
  read(fd, buf, 0x8);
  close(fd); // 0x1417
  srand();
  uint32_t addr = 0;
  while (addr <= 0x5fffffff || addr > 0xf7000000) {
    addr = rand();
  }

  return (void *)r;
}
