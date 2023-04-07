
void main(void)

{
  int iVar1;
  
  setvbuf(stdout,(char *)0x0,2,0);
  setvbuf(stdin,(char *)0x0,2,0);
  do {
    while( true ) {
      while( true ) {
        menu();
        iVar1 = read_int();
        if (iVar1 != 2) break;
        show_note();
      }
      if (2 < iVar1) break;
      if (iVar1 == 1) {
        add_note();
      }
      else {
LAB_08048a0e:
        puts("Invalid choice");
      }
    }
    if (iVar1 != 3) {
      if (iVar1 == 4) {
                    /* WARNING: Subroutine does not return */
        exit(0);
      }
      goto LAB_08048a0e;
    }
    del_note();
  } while( true );
}

