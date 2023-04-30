
undefined8 FUN_00100ecf(void)

{
  undefined8 *puVar1;
  int iVar2;
  undefined local_68 [64];
  undefined8 local_28;
  undefined8 local_20;
  char local_18 [16];
  
  FUN_00100d30();
  DAT_00302018 = open("/dev/urandom",0);
  read(DAT_00302018,&local_28,0x10);
  puVar1 = DAT_00302020;
  *DAT_00302020 = local_28;
  puVar1[1] = local_20;
  close(DAT_00302018);
  while( true ) {
    write(1,&DAT_00101152,3);
    __read_chk(0,local_18,0x10,0x10);
    if (local_18[0] == '2') break;
    if (local_18[0] == '3') {
      if (DAT_00302014 == 0) {
        puts("Invalid choice");
      }
      else {
        FUN_00100e76(local_68);
      }
    }
    else if (local_18[0] == '1') {
      if (DAT_00302014 == 0) {
        FUN_00100def(&local_28);
      }
      else {
        DAT_00302014 = 0;
      }
    }
    else {
      puts("Invalid choice");
    }
  }
  if (DAT_00302014 == 0) {
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  iVar2 = memcmp(&local_28,DAT_00302020,0x10);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}

