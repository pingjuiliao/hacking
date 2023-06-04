
void FUN_00100d8d(void)

{
  long lVar1;
  
  printf("Index :");
  lVar1 = FUN_00100b49();
  if (lVar1 < 0x10) {
    free(*(void **)(&DAT_00302040 + lVar1 * 8));
  }
  return;
}

