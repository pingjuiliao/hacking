
void setup(void)
{
  setvbuf(stdin,(char *)0x0,2,0);
  setvbuf(stdout,(char *)0x0,2,0);
  setvbuf(stderr,(char *)0x0,2,0);
  signal(0xe,FUN_00400927);
  alarm(0x3c);
  return;
}


void my_read(long param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = __read_chk(0,param_1,param_2,param_2);
  if (iVar1 < 1) {
    puts("read error");
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  if (*(char *)(param_1 + (long)iVar1 + -1) == '\n') {
    *(undefined *)(param_1 + (long)iVar1 + -1) = 0;
  }
  return;
}


void menu(void)

{
  puts("$$$$$$$$$$$$$$$$$$$$$$$");
  puts("      Tcache tear     ");
  puts("$$$$$$$$$$$$$$$$$$$$$$$");
  puts("  1. Malloc            ");
  puts("  2. Free              ");
  puts("  3. Info              ");
  puts("  4. Exit              ");
  puts("$$$$$$$$$$$$$$$$$$$$$$$");
  printf("Your choice :");
  return;
}

// 0x400b14
void my_malloc(void)
{
  ulong __size;
  
  printf("Size:");
  __size = read_longlong();
  if (__size < 0x100) {
    DAT_00602088 = malloc(__size);
    printf("Data:");
    my_read(DAT_00602088,(int)__size + -0x10);
    puts("Done !");
  }
  return;
}


void output_name(void)
{
  printf("Name :");
  write(1, &DAT_00602060, 0x20);
  return;
}


void main(void)
{
  long lVar1;
  uint local_c;
  
  setup();
  printf("Name:");
  my_read(&DAT_00602060,0x20);
  local_c = 0;
  do {
    while( true ) {
      while( true ) {
        menu();
        lVar1 = read_longlong();
        if (lVar1 != 2) break;
        if (local_c < 8) {
          free(DAT_00602088);
          local_c = local_c + 1;
        }
      }
      if (2 < lVar1) break;
      if (lVar1 == 1) {
        my_malloc();
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
    output_name();
  } while( true );
}


longlong read_longlong(void)
{
  longlong lVar1;
  long in_FS_OFFSET;
  char local_28 [24];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  __read_chk(0,local_28,0x17,0x18);
  lVar1 = atoll(local_28);
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar1;
}

