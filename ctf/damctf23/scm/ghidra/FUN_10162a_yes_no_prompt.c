
/* WARNING: Could not reconcile some variable overlaps */

ulong FUN_0010162a(undefined8 param_1)

{
  char *pcVar1;
  long in_FS_OFFSET;
  undefined8 local_1a;
  undefined2 local_12;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_1a = 0;
  local_12 = 0;
  printf("%s (y/n): ",param_1);
  pcVar1 = fgets((char *)&local_1a,9,stdin);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return (ulong)pcVar1 & 0xffffffffffffff00 | (ulong)((char)local_1a == 'y');
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

