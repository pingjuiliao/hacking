
void add_toxin(void)

{
  int iVar1;
  void *pvVar2;
  int local_24;
  ulong local_20 [2];
  
  puts("A new toxin! Fascinating.");
  printf("Toxin chemical formula length: ");
  __isoc99_scanf(&DAT_00102140,local_20);
  if (local_20[0] < 0xe1) {
    printf("Toxin index: ");
    __isoc99_scanf(&DAT_00102100,&local_24);
    iVar1 = local_24;
    if (((local_24 < 0) || (2 < local_24)) || (*(long *)(toxins + (long)local_24 * 8) != 0)) {
      puts("Invalid toxin index.");
    }
    else {
      *(ulong *)(sizes + (long)local_24 * 8) = local_20[0];
      pvVar2 = malloc(local_20[0]);
      *(void **)(toxins + (long)iVar1 * 8) = pvVar2;
      printf("Enter toxin formula: ");
      read(0,*(void **)(toxins + (long)local_24 * 8),local_20[0]);
    }
  }
  else {
    puts("Chemical formula too long.");
  }
  return;
}

