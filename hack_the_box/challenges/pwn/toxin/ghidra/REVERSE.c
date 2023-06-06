bool DAT_4050_toxinfreed = 0;
void* DAT_4060_toxins[3]
size_t DAT_4080_sizes[3]

void add_toxin(void)
{
  int iVar1;
  void *pvVar2;
  int local_24; // -0x1c(%rbp)
  ulong toxin_size[2]; // -0x18(%rbp)
  
  puts("A new toxin! Fascinating.");
  printf("Toxin chemical formula length: ");
  __isoc99_scanf("%lu",toxin_size);
  if (toxin_size[0] < 0xe1) {
    printf("Toxin index: ");
    __isoc99_scanf("%d",&local_24);
    iVar1 = local_24;
    if (((local_24 < 0) || (2 < local_24)) || (*(long *)(toxins + (long)local_24 * 8) != 0)) {
      puts("Invalid toxin index.");
    }
    else {
      *(ulong *)(sizes + (long)local_24 * 8) = toxin_size[0];
      pvVar2 = malloc(toxin_size[0]);
      *(void **)(toxins + (long)iVar1 * 8) = pvVar2;
      printf("Enter toxin formula: ");
      read(0,*(void **)(toxins + (long)local_24 * 8),toxin_size[0]);
    }
  }
  else {
    puts("Chemical formula too long.");
  }
  return;
}


void drink_toxin(void)
{
  int local_c;
  
  puts("This is dangerous testing, I\'m warning you!");
  printf("Toxin index: ");
  __isoc99_scanf("%d",&local_c);
  if (((local_c < 0) || (2 < local_c)) || (*(long *)(toxins + (long)local_c * 8) == 0)) {
    puts("Invalid toxin index.");
  }
  else if (toxinfreed == 0) {
    toxinfreed = 1;
    free(*(void **)(toxins + (long)local_c * 8));
  }
  else {
    puts("You can only drink toxins once, they\'re way too poisonous to try again.");
  }
  return;
}


void edit_toxin(void)
{
  int local_c;
  
  puts("Adjusting an error?");
  printf("Toxin index: ");
  __isoc99_scanf("%d",&local_c);
  if (((local_c < 0) || (2 < local_c)) || (*(long *)(toxins + (long)local_c * 8) == 0)) {
    puts("Invalid toxin index.");
  }
  else {
    printf("Enter toxin formula: ");
    read(0,*(void **)(toxins + (long)local_c * 8),*(size_t *)(sizes + (long)local_c * 8));
  }
  return;
}


void main(void)
{
  int iVar1;
  
  setvbuf(stdout,(char *)0x0,2,0);
  setvbuf(stderr,(char *)0x0,2,0);
  setvbuf(stdin,(char *)0x0,2,0);
  puts(
      "Welcome to Toxin, a low-capacity lab designed to store, record and keep track of chemical toxins."
      );
LAB_00101223:
  while (iVar1 = menu(), iVar1 == 4) {
    search_toxin();
  }
  if (iVar1 < 5) {
    if (iVar1 == 3) {
      drink_toxin();
      goto LAB_00101223;
    }
    if (iVar1 < 4) {
      if (iVar1 == 1) {
        add_toxin();
      }
      else {
        if (iVar1 != 2) goto LAB_00101286;
        edit_toxin();
      }
      goto LAB_00101223;
    }
  }
LAB_00101286:
  puts("Lab code not implemented.");
  goto LAB_00101223;
}


undefined4 menu(void)
{
  undefined4 local_c;
  
  puts("1. Record toxin");
  puts("2. Edit existing toxin record");
  puts("3. Drink toxin for testing");
  puts("4. Search for toxin record");
  puts("Enter your lab code.");
  printf("> ");
  __isoc99_scanf("%d",&local_c);
  return local_c;
}


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

