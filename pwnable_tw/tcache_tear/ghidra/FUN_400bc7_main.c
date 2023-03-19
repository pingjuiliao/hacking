
void FUN_00400bc7(void)

{
  long lVar1;
  uint local_c;
  
  FUN_00400948();
  printf("Name:");
  FUN_00400a25(&DAT_00602060,0x20);
  local_c = 0;
  do {
    while( true ) {
      while( true ) {
        FUN_00400a9c();
        lVar1 = FUN_004009c4();
        if (lVar1 != 2) break;
        if (local_c < 8) {
          free(DAT_00602088);
          local_c = local_c + 1;
        }
      }
      if (2 < lVar1) break;
      if (lVar1 == 1) {
        FUN_00400b14();
      }
      else {
LAB_00400c75:
        puts("Invalid choice");
      }
    }
    if (lVar1 != 3) {
      if (lVar1 == 4) {
                    /* WARNING: Subroutine does not return */
        exit(0);
      }
      goto LAB_00400c75;
    }
    FUN_00400b99();
  } while( true );
}

