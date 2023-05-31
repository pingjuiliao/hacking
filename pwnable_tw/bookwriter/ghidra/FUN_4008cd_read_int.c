
ulong FUN_004008cd(void)

{
  int iVar1;
  ulong uVar2;
  long in_FS_OFFSET;
  char local_28 [24];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = FUN_00400856(local_28,0x10);
  if (iVar1 < 0) {
    puts("read error");
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  uVar2 = atol(local_28);
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2 & 0xffffffff;
}

