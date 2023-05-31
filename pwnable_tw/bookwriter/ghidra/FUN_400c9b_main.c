
void FUN_00400c9b(void)

{
  undefined8 uVar1;
  
  setvbuf(stdout,(char *)0x0,2,0);
  puts("Welcome to the BookWriter !");
  FUN_00400bdf();
  do {
    FUN_0040093a();
    uVar1 = FUN_004008cd();
    switch(uVar1) {
    default:
      puts("Invalid choice");
      break;
    case 1:
      FUN_004009aa();
      break;
    case 2:
      FUN_00400a99();
      break;
    case 3:
      FUN_00400b27();
      break;
    case 4:
      FUN_00400c04();
      break;
    case 5:
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
  } while( true );
}

