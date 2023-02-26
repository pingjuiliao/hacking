
void FUN_00100f50(long param_1)

{
  int iVar1;
  
  printf("Index: ");
  iVar1 = FUN_0010138c();
  if (((-1 < iVar1) && (iVar1 < 0x10)) && (*(int *)(param_1 + (long)iVar1 * 0x18) == 1)) {
    *(undefined4 *)(param_1 + (long)iVar1 * 0x18) = 0;
    *(undefined8 *)(param_1 + (long)iVar1 * 0x18 + 8) = 0;
    free(*(void **)(param_1 + (long)iVar1 * 0x18 + 0x10));
    *(undefined8 *)(param_1 + (long)iVar1 * 0x18 + 0x10) = 0;
  }
  return;
}

