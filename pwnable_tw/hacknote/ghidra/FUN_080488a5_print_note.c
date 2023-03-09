
void FUN_080488a5(void)

{
  int iVar1;
  int in_GS_OFFSET;
  char local_14 [4];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  printf("Index :");
  read(0,local_14,4);
  iVar1 = atoi(local_14);
  if ((iVar1 < 0) || (DAT_0804a04c <= iVar1)) {
    puts("Out of bound!");
                    /* WARNING: Subroutine does not return */
    _exit(0);
  }
  if (*(int *)(&DAT_0804a050 + iVar1 * 4) != 0) {
    (***(code ***)(&DAT_0804a050 + iVar1 * 4))(*(undefined4 *)(&DAT_0804a050 + iVar1 * 4));
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

