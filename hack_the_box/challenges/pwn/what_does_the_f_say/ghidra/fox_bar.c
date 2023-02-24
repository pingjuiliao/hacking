
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
        menu();
        __isoc99_scanf(&DAT_0010209a,&local_14);
        if (local_14 != 1) break;
        drinks_menu();
      }
      if (local_14 == 2) break;
      puts("Invalid option!");
      goodbye();
    }
    food_menu();
  } while( true );
}

