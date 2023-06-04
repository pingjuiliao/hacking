
void FUN_0010118f(void)

{
  int iVar1;
  
  FUN_00100b60();
  do {
    while( true ) {
      while( true ) {
        FUN_00101117();
        iVar1 = FUN_00100ca9();
        if (iVar1 != 3) break;
        FUN_0010106d();
      }
      if (3 < iVar1) break;
      if (iVar1 == 1) {
        FUN_00100e6c();
      }
      else if (iVar1 == 2) {
        FUN_00100f3c();
      }
      else {
LAB_0010120f:
        puts("Invalid choice");
      }
    }
    if (iVar1 == 4) {
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if (iVar1 != 0x1305) goto LAB_0010120f;
    FUN_00100e34();
  } while( true );
}

