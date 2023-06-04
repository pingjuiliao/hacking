
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

