
void FUN_00100dd5(void)

{
  long lVar1;
  
  FUN_00100ac1();
  while( true ) {
    while( true ) {
      FUN_00100c21();
      lVar1 = FUN_00100b49();
      if (lVar1 != 2) break;
      FUN_00100d8d();
    }
    if (lVar1 == 3) break;
    if (lVar1 == 1) {
      FUN_00100c8d();
    }
    else {
      puts("Invalid Choice !");
    }
  }
                    /* WARNING: Subroutine does not return */
  _exit(0);
}

