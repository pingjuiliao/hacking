// note: 0x804a080


// The shellcode check
undefined4 check(char *param_1)
{
  ushort **ppuVar1;
  size_t sVar2;
  uint local_10;
  
  local_10 = 0;
  while( true ) {
    sVar2 = strlen(param_1);
    if (sVar2 <= local_10) {
      return 1; // success
    }
    if ((param_1[local_10] != ' ') &&
       (ppuVar1 = __ctype_b_loc(), ((*ppuVar1)[param_1[local_10]] & 8) == 0)) break;
    local_10 = local_10 + 1;
  }
  // Failed
  return 0;
}



void add_note(void)
{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int in_GS_OFFSET;
  char local_18 [8];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  printf("Index :");
  iVar1 = read_int();
  if (10 < iVar1) {
    puts("Out of bound !!");
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  printf("Name :");
  read_input(local_18,8);
  iVar2 = check(local_18);
  if (iVar2 != 0) {
    pcVar3 = strdup(local_18);
    *(char **)(note + iVar1 * 4) = pcVar3;
    puts("Done !");
    if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
  puts("It must be a alnum name !");
                    /* WARNING: Subroutine does not return */
  exit(-1);
}


void show_note(void)
{
  int iVar1;
  
  printf("Index :");
  iVar1 = read_int();
  if (10 < iVar1) {
    puts("Out of bound !!");
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  if (*(int *)(note + iVar1 * 4) != 0) {
    printf("Name : %s\n",*(undefined4 *)(note + iVar1 * 4));
  }
  return;
}


void del_note(void)
{
  int iVar1;
  
  printf("Index :");
  iVar1 = read_int();
  if (10 < iVar1) {
    puts("Out of bound !!");
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  free(*(void **)(note + iVar1 * 4));
  *(undefined4 *)(note + iVar1 * 4) = 0;
  return;
}


void main(void)
{
  int iVar1;
  
  setvbuf(stdout,(char *)0x0,2,0);
  setvbuf(stdin,(char *)0x0,2,0);
  do {
    while( true ) {
      while( true ) {
        menu();
        iVar1 = read_int();
        if (iVar1 != 2) break;
        show_note();
      }
      if (2 < iVar1) break;
      if (iVar1 == 1) {
        add_note();
      }
      else {
LAB_08048a85:
        puts("Invalid choice");
      }
    }
    if (iVar1 != 3) {
      if (iVar1 == 4) {
                    /* WARNING: Subroutine does not return */
        exit(0);
      }
      goto LAB_08048a85;
    }
    del_note();
  } while( true );
}

void menu(void)
{
  puts("-----------------------------------");
  puts("             AliveNote             ");
  puts("-----------------------------------");
  puts(" 1. Add a name                     ");
  puts(" 2. show a name on the note        ");
  puts(" 3. delete a name int the note     ");
  puts(" 4. Exit                           ");
  puts("-----------------------------------");
  printf("Your choice :");
  return;
}


void read_input(void *param_1,size_t param_2)
{
  ssize_t sVar1;
  
  sVar1 = read(0,param_1,param_2);
  if (sVar1 < 1) {
    puts("read error");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  if (*(char *)((int)param_1 + sVar1 + -1) == '\n') {
    *(undefined *)((int)param_1 + sVar1 + -1) = 0;
  }
  return;
}


int read_int(void)
{
  ssize_t sVar1;
  int iVar2;
  int in_GS_OFFSET;
  char local_20 [16];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  sVar1 = read(0,local_20,0xf);
  if (sVar1 < 1) {
    puts("read error");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  iVar2 = atoi(local_20);
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}


