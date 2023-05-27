
int FUN_00100dd0(void)

{
  int iVar1;
  long in_FS_OFFSET;
  uint local_14;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  if (DAT_00302024 == 0) {
    iVar1 = puts("No flower in the garden");
  }
  else {
    __printf_chk(1,"Which flower do you want to remove from the garden:");
    __isoc99_scanf(&DAT_0010129f,&local_14);
    if ((local_14 < 100) && ((undefined4 *)(&DAT_00302040)[local_14] != (undefined4 *)0x0)) {
      *(undefined4 *)(&DAT_00302040)[local_14] = 0;
      free(*(void **)((&DAT_00302040)[local_14] + 8));
      iVar1 = puts("Successful");
    }
    else {
      puts("Invalid choice");
      iVar1 = 0;
    }
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

