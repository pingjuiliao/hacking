
void FUN_00402960(void)

{
  long lVar1;
  
  lVar1 = 1;
  do {
    (*(code *)(&PTR_FUN_004b40f0)[lVar1])();
    lVar1 = lVar1 + -1;
  } while (lVar1 != -1);
  FUN_0048e32c();
  return;
}

