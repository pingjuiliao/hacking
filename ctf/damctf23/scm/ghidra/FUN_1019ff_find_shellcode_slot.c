
long FUN_001019ff(void)

{
  long lVar1;
  
  lVar1 = 0;
  do {
    if ((&DAT_00104120)[lVar1] == 0) {
      return lVar1;
    }
    lVar1 = lVar1 + 1;
  } while (lVar1 != 5);
  return 0xffffffff;
}

