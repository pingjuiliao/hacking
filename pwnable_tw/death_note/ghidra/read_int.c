
int read_int(void)

{
  ssize_t sVar1;
  int iVar2;
  int in_GS_OFFSET;
  char local_20 [16];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  sVar1 = read(0,local_20,0xf);
  if (sVar1 < 1) {
    puts("read error");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  iVar2 = atoi(local_20);
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

