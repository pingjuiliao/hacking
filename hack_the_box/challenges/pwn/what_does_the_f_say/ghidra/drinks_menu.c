
void drinks_menu(void)

{
  long in_FS_OFFSET;
  int local_3c;
  char local_38 [40];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  memset(local_38,0,0x1e);
  puts(
      "\n1. Milky way (4.90 s.rocks)\n2. Kryptonite vodka (6.90 s.rocks)\n3. Deathstar(70.00 s.rocks)"
      );
  __isoc99_scanf(&DAT_0010209a,&local_3c);
  if (local_3c == 1) {
    srocks = srocks - 4.9;
    srock_check();
    if (srocks <= 20.0) {
      puts("\nYou have less than 20 space rocks!");
    }
    enjoy("Milky way");
  }
  else if (local_3c == 2) {
    srock_check();
    puts("\nRed or Green Kryptonite?");
    read(0,local_38,0x1d);
    printf(local_38);
    warning();
  }
  else if (local_3c == 3) {
    srocks = srocks - 69.99;
    srock_check();
    if (srocks <= 20.0) {
      puts("\nYou have less than 20 space rocks!");
    }
    enjoy("Deathstar");
  }
  else {
    puts("Invalid option!");
    goodbye();
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

