
void handler(void)

{
  int iVar1;
  int in_GS_OFFSET;
  char local_26 [22];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  do {
    printf("> ");
    fflush(stdout);
    my_read(local_26,0x15);
    iVar1 = atoi(local_26);
    switch(iVar1) {
    default:
      puts("It\'s not a choice! Idiot.");
      break;
    case 1:
      list();
      break;
    case 2:
      add();
      break;
    case 3:
      delete();
      break;
    case 4:
      cart();
      break;
    case 5:
      checkout();
      break;
    case 6:
      puts("Thank You for Your Purchase!");
      if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
  } while( true );
}

