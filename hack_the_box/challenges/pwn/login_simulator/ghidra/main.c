
undefined8 main(void)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  long in_FS_OFFSET;
  int local_b0;
  int local_ac;
  undefined local_a8 [152];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  bVar1 = false;
  setup();
  banner();
  do {
    menu();
    iVar2 = __isoc99_scanf(&DAT_00102637,&local_b0);
    if (iVar2 < 0) {
      puts("Something went wrong.\n");
      uVar3 = 1;
LAB_00101657:
      if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
        return uVar3;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    if (local_b0 == 3) {
      uVar3 = 0;
      goto LAB_00101657;
    }
    if (3 < local_b0) {
LAB_0010163c:
      puts("Invalid option.\n");
      uVar3 = 1;
      goto LAB_00101657;
    }
    if (local_b0 == 1) {
      local_ac = _register(local_a8);
      if (local_ac < 0) {
        uVar3 = 1;
        goto LAB_00101657;
      }
      bVar1 = true;
    }
    else {
      if (local_b0 != 2) goto LAB_0010163c;
      if (bVar1) {
        iVar2 = _login(local_a8,local_ac);
        if (iVar2 == 0) {
          puts("Invalid username! :)");
        }
        else {
          puts("Good job! :^)");
        }
      }
      else {
        puts("You need to register first.");
      }
    }
  } while( true );
}

