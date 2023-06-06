
void edit_toxin(void)

{
  int local_c;
  
  puts("Adjusting an error?");
  printf("Toxin index: ");
  __isoc99_scanf(&DAT_00102100,&local_c);
  if (((local_c < 0) || (2 < local_c)) || (*(long *)(toxins + (long)local_c * 8) == 0)) {
    puts("Invalid toxin index.");
  }
  else {
    printf("Enter toxin formula: ");
    read(0,*(void **)(toxins + (long)local_c * 8),*(size_t *)(sizes + (long)local_c * 8));
  }
  return;
}

