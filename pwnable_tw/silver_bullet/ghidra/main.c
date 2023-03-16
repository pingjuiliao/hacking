
undefined4 main(void)

{
  int iVar1;
  undefined4 local_40;
  undefined *local_3c;
  undefined local_38 [48];
  undefined4 local_8;
  
  init_proc();
  local_8 = 0;
  memset(local_38,0,0x30);
  local_40 = 0x7fffffff;
  local_3c = &DAT_08048d06;
  do {
    while( true ) {
      while( true ) {
        menu();
        iVar1 = read_int();
        if (iVar1 != 2) break;
        power_up(local_38);
      }
      if (2 < iVar1) break;
      if (iVar1 == 1) {
        create_bullet(local_38);
      }
      else {
LAB_08048a05:
        puts("Invalid choice");
      }
    }
    if (iVar1 != 3) {
      if (iVar1 == 4) {
        puts("Don\'t give up !");
                    /* WARNING: Subroutine does not return */
        exit(0);
      }
      goto LAB_08048a05;
    }
    iVar1 = beat(local_38,&local_40);
    if (iVar1 != 0) {
      return 0;
    }
    puts("Give me more power !!");
  } while( true );
}

