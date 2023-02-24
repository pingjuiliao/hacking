
void setup(void)

{
  long lVar1;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  setvbuf(stdin,(char *)0x0,2,0);
  setvbuf(stdout,(char *)0x0,2,0);
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


void welcome(void)

{
  long lVar1;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  puts("\nWelcome to Fox space bar!");
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


undefined8 main(void)
{
  long canary;
  long in_FS_OFFSET;
  
  canary = *(long *)(in_FS_OFFSET + 0x28);
  setup(); // setvbuf
  welcome(); // print welcome message
  fox_bar();
  if (canary != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}


void fox_bar(void)

{
  long in_FS_OFFSET;
  int local_14;
  undefined8 local_10;
  
  local_10 = *(undefined8 *)(in_FS_OFFSET + 0x28);
  do {
    while( true ) {
      while( true ) {
        printf("\nCurrent space rocks: %.2f\n",(double)srocks);
        srock_check();
        menu(); // print menu
        __isoc99_scanf(&DAT_0010209a,&local_14);
        if (local_14 != 1) break;
        drinks_menu(); // option 1
      }
      if (local_14 == 2) break; // option 2
      puts("Invalid option!");
      goodbye(); // exit
    }
    food_menu();
  } while( true );
}


void menu(void)

{
  long lVar1;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  puts("\n1. Space drinks\n2. Space food");
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


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
    read(0,local_38,0x1d); // 0x1d == 29
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


void warning(void)

{
  int iVar1;
  long in_FS_OFFSET;
  char local_28 [24];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  if (20.0 < srocks) {
    enjoy("Kryptonite vodka");
    srocks = srocks - 6.9;
    srock_check();
  }
  else {
    puts("\nYou have less than 20 space rocks! Are you sure you want to buy it?");
    __isoc99_scanf(&DAT_0010215d,local_28);
    iVar1 = strcmp(local_28,"yes");
    if (iVar1 == 0) {
      srocks = srocks - 6.9;
      srock_check();
      enjoy("Kryptonite vodka");
    }
    else {
      iVar1 = strcmp(local_28,"no");
      if (iVar1 == 0) {
        puts("\nA Milky way is nice too if you want..");
      }
    }
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


void enjoy(undefined8 param_1)

{
  long lVar1;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  printf("\nEnjoy your %s!\n",param_1);
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


void srock_check(void)

{
  long lVar1;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if (srocks < 0.0) {
    puts("\nNot enough space rocks!");
    goodbye();
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

