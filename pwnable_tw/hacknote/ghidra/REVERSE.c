void main(void)
{
  int iVar1;
  int in_GS_OFFSET;
  char local_18 [4];
  undefined4 canary;
  undefined *puStack12;
  
  puStack12 = &stack0x00000004;
  canary = *(undefined4 *)(in_GS_OFFSET + 0x14);
  setvbuf(stdout,(char *)0x0,2,0);
  setvbuf(stdin,(char *)0x0,2,0);
  do {
    while( true ) {
      while( true ) {
        prompt();
        read(0,local_18,4);
        iVar1 = atoi(local_18);
        if (iVar1 != 2) break;
        delete_note();
      }
      if (2 < iVar1) break;
      if (iVar1 == 1) {
        add_note();
      }
      else {
LAB_08048a96:
        puts("Invalid choice");
      }
    }
    if (iVar1 != 3) {
      if (iVar1 == 4) {
                    /* WARNING: Subroutine does not return */
        exit(0);
      }
      goto LAB_08048a96;
    }
    print_note();
  } while( true );
}

void add_note(void)
{
  int iVar1;
  void *pvVar2;
  size_t __size;
  int in_GS_OFFSET;
  int local_20;
  char local_18 [8];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (DAT_num_notes < 6) {
    for (local_20 = 0; local_20 < 5; local_20 = local_20 + 1) {
      if (*(int *)(&DAT_0804a050 + local_20 * 4) == 0) {
        pvVar2 = malloc(8);
        *(void **)(&DAT_0804a050 + local_20 * 4) = pvVar2;
        if (*(int *)(&DAT_0804a050 + local_20 * 4) == 0) {
          puts("Alloca Error");
                    /* WARNING: Subroutine does not return */
          exit(-1);
        }
        **(code ***)(&DAT_0804a050 + local_20 * 4) = puts_note_content;
        printf("Note size :");
        read(0,local_18,8);
        __size = atoi(local_18);
        iVar1 = *(int *)(&DAT_0804a050 + local_20 * 4);
        pvVar2 = malloc(__size);
        *(void **)(iVar1 + 4) = pvVar2;
        if (*(int *)(*(int *)(&DAT_0804a050 + local_20 * 4) + 4) == 0) {
          puts("Alloca Error");
                    /* WARNING: Subroutine does not return */
          exit(-1);
        }
        printf("Content :");
        read(0,*(void **)(*(int *)(&DAT_0804a050 + local_20 * 4) + 4),__size);
        puts("Success !");
        DAT_num_notes = DAT_num_notes + 1;
        break;
      }
    }
  }
  else {
    puts("Full");
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


void delete_note(void)
{
  int iVar1;
  int in_GS_OFFSET;
  char local_14 [4];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  printf("Index :");
  read(0,local_14,4);
  iVar1 = atoi(local_14);
  if ((iVar1 < 0) || (DAT_num_notes <= iVar1)) {
    puts("Out of bound!");
                    /* WARNING: Subroutine does not return */
    _exit(0);
  }
  if (*(int *)(&DAT_0804a050 + iVar1 * 4) != 0) {
    free(*(void **)(*(int *)(&DAT_0804a050 + iVar1 * 4) + 4));
    free(*(void **)(&DAT_0804a050 + iVar1 * 4));
    puts("Success");
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


void print_note(void)
{
  int iVar1;
  int in_GS_OFFSET;
  char local_14 [4];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  printf("Index :");
  read(0,local_14,4);
  iVar1 = atoi(local_14);
  if ((iVar1 < 0) || (DAT_num_notes <= iVar1)) {
    puts("Out of bound!");
                    /* WARNING: Subroutine does not return */
    _exit(0);
  }
  if (*(int *)(&DAT_0804a050 + iVar1 * 4) != 0) {
    (***(code ***)(&DAT_0804a050 + iVar1 * 4))(*(undefined4 *)(&DAT_0804a050 + iVar1 * 4));
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


void prompt(void)
{
  puts("----------------------");
  puts("       HackNote       ");
  puts("----------------------");
  puts(" 1. Add note          ");
  puts(" 2. Delete note       ");
  puts(" 3. Print note        ");
  puts(" 4. Exit              ");
  puts("----------------------");
  printf("Your choice :");
  return;
}



void puts_note_content(int param_1)
{
  puts(*(char **)(param_1 + 4));
  return;
}

