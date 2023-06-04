
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00100b60(void)

{
  time_t tVar1;
  uint local_c;
  
  local_c = 0;
  setvbuf(_stdout,(char *)0x0,2,0);
  setvbuf(_stdin,(char *)0x0,2,0);
  tVar1 = time((time_t *)0x0);
  srand((uint)tVar1);
  for (; (int)local_c < 0x10001; local_c = local_c & 0xfffff000) {
    local_c = rand();
  }
  DAT_00302018 = mmap((void *)(long)(int)local_c,0x1000,3,0x22,-1,0);
  if (DAT_00302018 == (void *)0xffffffffffffffff) {
    puts("mmap error");
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  return;
}

