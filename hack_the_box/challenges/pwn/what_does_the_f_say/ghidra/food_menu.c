
void food_menu(void)

{
  long in_FS_OFFSET;
  int local_14;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  puts(
      "\n1. E.Tarts (6.90 s.rocks)\n2. Space Brownies (5.90 s.rocks)\n3. Spacecream (7.90 s.rocks) "
      );
  __isoc99_scanf(&DAT_0010209a,&local_14);
  if (local_14 == 3) {
    srocks = srocks - 7.9;
    srock_check();
    if (srocks <= 20.0) {
      puts("\nYou have less than 20 space rocks!");
    }
    enjoy("Spacecream");
    goto code_r0x001013fa;
  }
  if (local_14 < 4) {
    if (local_14 == 1) {
      srocks = srocks - 6.9;
      srock_check();
      if (srocks <= 20.0) {
        puts("\nYou have less than 20 space rocks!");
      }
      enjoy("E.Tarts");
      goto code_r0x001013fa;
    }
    if (local_14 == 2) {
      srocks = srocks - 5.9;
      srock_check();
      if (srocks <= 20.0) {
        puts("\nYou have less than 20 space rocks!");
      }
      enjoy("Space Brownies");
      goto code_r0x001013fa;
    }
  }
  puts("Invalid option!");
  goodbye();
code_r0x001013fa:
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

