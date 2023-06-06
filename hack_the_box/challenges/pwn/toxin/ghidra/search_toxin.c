
void search_toxin(void)

{
  int iVar1;
  uint local_14;
  char local_e [6];
  
  puts("Time to search the archives!");
  memset(local_e,0,6);
  printf("Enter search term: ");
  read(0,local_e,5);
  local_14 = 0;
  while( true ) {
    if (2 < (int)local_14) {
      printf(local_e);
      puts(" not found.");
      return;
    }
    if ((*(long *)(toxins + (long)(int)local_14 * 8) != 0) &&
       (iVar1 = strcmp(local_e,*(char **)(toxins + (long)(int)local_14 * 8)), iVar1 == 0)) break;
    local_14 = local_14 + 1;
  }
  printf("Found at index %d!\n",(ulong)local_14);
  return;
}

