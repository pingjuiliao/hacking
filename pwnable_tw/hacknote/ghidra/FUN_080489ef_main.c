
void FUN_080489ef(void)

{
  int iVar1;
  int in_GS_OFFSET;
  char local_18 [4];
  undefined4 local_14;
  undefined *puStack12;
  
  puStack12 = &stack0x00000004;
  local_14 = *(undefined4 *)(in_GS_OFFSET + 0x14);
  setvbuf(stdout,(char *)0x0,2,0);
  setvbuf(stdin,(char *)0x0,2,0);
  do {
    while( true ) {
      while( true ) {
        FUN_08048956();
        read(0,local_18,4);
        iVar1 = atoi(local_18);
        if (iVar1 != 2) break;
        FUN_080487d4();
      }
      if (2 < iVar1) break;
      if (iVar1 == 1) {
        FUN_08048646();
      }
      else {
LAB_08048a96:
        puts("Invalid choice");
      }
    }
    if (iVar1 != 3) {
      if (iVar1 == 4) {
                    /* WARNING: Subroutine does not return */
        exit(0);
      }
      goto LAB_08048a96;
    }
    FUN_080488a5();
  } while( true );
}

