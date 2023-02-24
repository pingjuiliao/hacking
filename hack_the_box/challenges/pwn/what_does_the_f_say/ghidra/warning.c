
void warning(void)

{
  int iVar1;
  long in_FS_OFFSET;
  char local_28 [24];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  if (20.0 < srocks) {
    enjoy("Kryptonite vodka");
    srocks = srocks - 6.9;
    srock_check();
  }
  else {
    puts("\nYou have less than 20 space rocks! Are you sure you want to buy it?");
    __isoc99_scanf(&DAT_0010215d,local_28);
    iVar1 = strcmp(local_28,"yes");
    if (iVar1 == 0) {
      srocks = srocks - 6.9;
      srock_check();
      enjoy("Kryptonite vodka");
    }
    else {
      iVar1 = strcmp(local_28,"no");
      if (iVar1 == 0) {
        puts("\nA Milky way is nice too if you want..");
      }
    }
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

