
void main(void)

{
  long in_FS_OFFSET;
  int local_14;
  undefined8 local_10;
  
  local_10 = *(undefined8 *)(in_FS_OFFSET + 0x28);
  local_14 = 0;
  init_proc();
  do {
    while( true ) {
      while( true ) {
        menu();
        __isoc99_scanf(&DAT_0040212f,&local_14);
        if (local_14 != 2) break;
        reallocate();
      }
      if (2 < local_14) break;
      if (local_14 == 1) {
        allocate();
      }
      else {
LAB_00401772:
        puts("Invalid Choice");
      }
    }
    if (local_14 != 3) {
      if (local_14 == 4) {
                    /* WARNING: Subroutine does not return */
        _exit(0);
      }
      goto LAB_00401772;
    }
    rfree();
  } while( true );
}

