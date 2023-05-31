
void FUN_00400c04(void)

{
  long in_FS_OFFSET;
  int local_14;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_14 = 0;
  printf("Author : %s\n",&DAT_00602060);
  printf("Page : %u\n",(ulong)DAT_00602040);
  printf("Do you want to change the author ? (yes:1 / no:0) ");
  __isoc99_scanf(&DAT_00400f83,&local_14);
  if (local_14 == 1) {
    FUN_00400bdf();
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

