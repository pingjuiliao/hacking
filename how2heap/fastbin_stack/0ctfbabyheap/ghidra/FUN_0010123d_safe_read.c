
ulong FUN_0010123d(long param_1,long param_2)

{
  int *piVar1;
  ulong uVar2;
  long in_FS_OFFSET;
  char local_21;
  ulong local_20;
  ssize_t local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_2 == 0) {
    uVar2 = 0;
  }
  else {
    local_20 = 0;
    do {
      while( true ) {
        if (param_2 - 1U <= local_20) goto LAB_001012e7;
        local_18 = read(0,&local_21,1);
        if (local_18 < 1) break;
        if (local_21 == '\n') goto LAB_001012e7;
        *(char *)(param_1 + local_20) = local_21;
        local_20 = local_20 + 1;
      }
      piVar1 = __errno_location();
    } while ((*piVar1 == 0xb) || (piVar1 = __errno_location(), *piVar1 == 4));
LAB_001012e7:
    *(undefined *)(local_20 + param_1) = 0;
    uVar2 = local_20;
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

