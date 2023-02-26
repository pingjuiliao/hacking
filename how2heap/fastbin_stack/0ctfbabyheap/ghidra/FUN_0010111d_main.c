
undefined8 FUN_0010111d(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00100b70();
  do {
    FUN_00100cf4();
    uVar2 = FUN_0010138c();
    switch(uVar2) {
    case 1:
      FUN_00100d48(uVar1);
      break;
    case 2:
      FUN_00100e7f(uVar1);
      break;
    case 3:
      FUN_00100f50(uVar1);
      break;
    case 4:
      FUN_00101051(uVar1);
      break;
    case 5:
      return 0;
    }
  } while( true );
}

