
int _register(undefined8 param_1)

{
  int iVar1;
  long in_FS_OFFSET;
  int local_14;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  printf("{i} Username length: ");
  iVar1 = __isoc99_scanf(&DAT_00102637,&local_14);
  if (iVar1 < 0) {
    puts("Something went wrong!");
    local_14 = -1;
  }
  else if ((local_14 < 1) || (0x80 < local_14)) {
    puts("Invalid length.");
    local_14 = -1;
  }
  else {
    printf("{i} Enter username: ");
    getInput(param_1,local_14);
    puts("Username registered successfully!");
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_14;
}

