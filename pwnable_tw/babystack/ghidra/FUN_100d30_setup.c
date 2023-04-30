
void FUN_00100d30(void)

{
  signal(0xe,FUN_00100d0f);
  alarm(0x708);
  DAT_00302020 = mmap((void *)0x0,0x1000,3,0x22,-1,0);
  if (DAT_00302020 == (void *)0xffffffffffffffff) {
    puts("mmap error");
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  setvbuf(stdin,(char *)0x0,2,0);
  setvbuf(stdout,(char *)0x0,2,0);
  return;
}

