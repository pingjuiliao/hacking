
int read_input(long param_1,undefined4 param_2)
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
  return iVar1;
}


ulong read_int(void)
{
  int iVar1;
  ulong uVar2;
  long in_FS_OFFSET;
  char local_28 [24];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = read_input(local_28,0x10);
  if (iVar1 < 0) {
    puts("read error");
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  uVar2 = atol(local_28);
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2 & 0xffffffff;
}


void menu(void)
{
  puts("----------------------");
  puts("      BookWriter      ");
  puts("----------------------");
  puts(" 1. Add a page        ");
  puts(" 2. View a page       ");
  puts(" 3. Edit a page       ");
  puts(" 4. Information       ");
  puts(" 5. Exit              ");
  puts("----------------------");
  printf("Your choice :");
  return;
}


void add_bookpage(void)
{
  size_t __size;
  void *pvVar1;
  uint local_1c;
  
  local_1c = 0;
  while( true ) {
    if (8 < local_1c) {
      puts("You can\'t add new page anymore!");
      return;
    }
    if (*(long *)(&DAT_006020a0 + (ulong)local_1c * 8) == 0) break;
    local_1c = local_1c + 1;
  }
  printf("Size of page :");
  __size = read_int();
  pvVar1 = malloc(__size);
  if (pvVar1 != (void *)0x0) {
    printf("Content :");
    read_input(pvVar1,__size & 0xffffffff);
    *(void **)(&DAT_006020a0 + (ulong)local_1c * 8) = pvVar1;
    *(size_t *)(&DAT_006020e0 + (ulong)local_1c * 8) = __size;
    DAT_00602040 = DAT_00602040 + 1;
    puts("Done !");
    return;
  }
  puts("Error !");
                    /* WARNING: Subroutine does not return */
  exit(0);
}


void view_bookpage(void)
{
  uint uVar1;
  
  printf("Index of page :");
  uVar1 = read_int();
  if (7 < uVar1) {
    puts("out of page:");
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  if (*(long *)(&DAT_006020a0 + (ulong)uVar1 * 8) == 0) {
    puts("Not found !");
  }
  else {
    printf("Page #%u \n",(ulong)uVar1);
    printf("Content :\n%s\n",*(undefined8 *)(&DAT_006020a0 + (ulong)uVar1 * 8));
  }
  return;
}


void edit_bookpage(void)
{
  uint uVar1;
  size_t sVar2;
  
  printf("Index of page :");
  uVar1 = read_int();
  if (7 < uVar1) {
    puts("out of page:");
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  if (*(long *)(&DAT_006020a0 + (ulong)uVar1 * 8) == 0) {
    puts("Not found !");
  }
  else {
    printf("Content:");
    read_input(*(undefined8 *)(&DAT_006020a0 + (ulong)uVar1 * 8),
                 *(ulong *)(&DAT_006020e0 + (ulong)uVar1 * 8) & 0xffffffff);
    sVar2 = strlen(*(char **)(&DAT_006020a0 + (ulong)uVar1 * 8));
    *(size_t *)(&DAT_006020e0 + (ulong)uVar1 * 8) = sVar2;
    puts("Done !");
  }
  return;
}


void edit_author(void)
{
  printf("Author :");
  read_input(&DAT_00602060,0x40);
  return;
}


void info(void)
{
  long in_FS_OFFSET;
  int local_14;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_14 = 0;
  printf("Author : %s\n",&DAT_00602060);
  printf("Page : %u\n",(ulong)DAT_00602040);
  printf("Do you want to change the author ? (yes:1 / no:0) ");
  __isoc99_scanf(&DAT_00400f83,&local_14);
  if (local_14 == 1) {
    edit_author();
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


void main(void)
{
  undefined8 uVar1;
  
  setvbuf(stdout,(char *)0x0,2,0);
  puts("Welcome to the BookWriter !");
  edit_author();
  do {
    menu();
    uVar1 = read_int();
    switch(uVar1) {
    default:
      puts("Invalid choice");
      break;
    case 1:
      add_bookpage();
      break;
    case 2:
      view_bookpage();
      break;
    case 3:
      edit_bookpage();
      break;
    case 4:
      info();
      break;
    case 5:
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
  } while( true );
}

