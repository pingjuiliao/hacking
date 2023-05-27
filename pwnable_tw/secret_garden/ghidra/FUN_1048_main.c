
void FUN_00101048(void)

{
  ulong uVar1;
  long in_FS_OFFSET;
  char acStack_28 [8];
  undefined8 local_20;
  
  local_20 = *(undefined8 *)(in_FS_OFFSET + 0x28);
  FUN_00100fe1();
  do {
    FUN_00100b6a();
    read(0,acStack_28,4);
    uVar1 = strtol(acStack_28,(char **)0x0,10);
    switch(uVar1 & 0xffffffff) {
    default:
      puts("Invalid choice");
      break;
    case 1:
      FUN_00100c32();
      break;
    case 2:
      FUN_00100f1d();
      break;
    case 3:
      FUN_00100dd0();
      break;
    case 4:
      FUN_00100ea1();
      break;
    case 5:
      puts("See you next time.");
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
  } while( true );
}

