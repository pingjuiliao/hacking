
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

