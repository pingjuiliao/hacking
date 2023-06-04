/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void alloc_data(void)
{
  ulong __size;
  void *pvVar1;
  int local_14;
  
  local_14 = 0;
  while( true ) {
    if (0xf < local_14) {
      puts("You can\'t alloc_data anymore !");
      return;
    }
    if (*(long *)(&DAT_00302040 + (long)local_14 * 8) == 0) break;
    local_14 = local_14 + 1;
  }
  printf("Size :");
  __size = read_int();
  if (0x78 < __size) {
    return;
  }
  pvVar1 = malloc(__size);
  *(void **)(&DAT_00302040 + (long)local_14 * 8) = pvVar1;
  if (*(long *)(&DAT_00302040 + (long)local_14 * 8) != 0) {
    printf("Data :");
    read_input(*(undefined8 *)(&DAT_00302040 + (long)local_14 * 8),__size & 0xffffffff);
    return;
  }
  puts("Error!");
                    /* WARNING: Subroutine does not return */
  _exit(-1);
}

void free_data(void)
{
  long lVar1;
  
  printf("Index :");
  lVar1 = read_int();
  // VULN: allow negative
  if (lVar1 < 0x10) {
    free(*(void **)(&DAT_00302040 + lVar1 * 8));
  }
  return;
}


void main(void)
{
  long lVar1;
  
  setup();
  while( true ) {
    while( true ) {
      menu();
      lVar1 = read_int();
      if (lVar1 != 2) break;
      free_data();
    }
    if (lVar1 == 3) break;
    if (lVar1 == 1) {
      alloc_data();
    }
    else {
      puts("Invalid Choice !");
    }
  }
                    /* WARNING: Subroutine does not return */
  _exit(0);
}

void setup(void)
{
  setvbuf(_stdin,(char *)0x0,2,0);
  setvbuf(_stdout,(char *)0x0,2,0);
  setvbuf(_stderr,(char *)0x0,2,0);
  signal(0xe,FUN_00100aa0);
  alarm(0x3c);
  return;
}

longlong read_int(void)
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

void read_input(long param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = __read_chk(0,param_1,param_2,param_2);
  if (iVar1 < 0) {
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
  puts("***********************");
  puts("     Heap Paradise     ");
  puts("***********************");
  puts(" 1. alloc_data           ");
  puts(" 2. Free               ");
  puts(" 3. Exit               ");
  puts("***********************");
  printf("You Choice:");
  return;
}


