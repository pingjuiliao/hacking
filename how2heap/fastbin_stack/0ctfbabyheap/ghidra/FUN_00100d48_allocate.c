
void FUN_00100d48(long param_1)

{
  void *pvVar1;
  uint local_18;
  int local_14;
  
  local_18 = 0;
  while( true ) {
    if (0xf < (int)local_18) {
      return;
    }
    if (*(int *)(param_1 + (long)(int)local_18 * 0x18) == 0) break;
    local_18 = local_18 + 1;
  }
  printf("Size: ");
  local_14 = FUN_0010138c();
  if (local_14 < 1) {
    return;
  }
  if (0x1000 < local_14) {
    local_14 = 0x1000;
  }
  pvVar1 = calloc((long)local_14,1);
  if (pvVar1 != (void *)0x0) {
    *(undefined4 *)(param_1 + (long)(int)local_18 * 0x18) = 1;
    *(long *)((long)(int)local_18 * 0x18 + param_1 + 8) = (long)local_14;
    *(void **)((long)(int)local_18 * 0x18 + param_1 + 0x10) = pvVar1;
    printf("Allocate Index %d\n",(ulong)local_18);
    return;
  }
                    /* WARNING: Subroutine does not return */
  exit(-1);
}

