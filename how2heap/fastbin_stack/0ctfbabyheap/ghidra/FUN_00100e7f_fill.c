
void FUN_00100e7f(long param_1)

{
  int iVar1;
  int iVar2;
  
  printf("Index: ");
  iVar1 = FUN_0010138c();
  if (((-1 < iVar1) && (iVar1 < 0x10)) && (*(int *)(param_1 + (long)iVar1 * 0x18) == 1)) {
    printf("Size: ");
    iVar2 = FUN_0010138c();
    if (0 < iVar2) {
      printf("Content: ");
      FUN_001011b2(*(undefined8 *)(param_1 + (long)iVar1 * 0x18 + 0x10),(long)iVar2);
    }
  }
  return;
}

