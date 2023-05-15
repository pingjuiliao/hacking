
void rfree(void)

{
  ulong uVar1;
  
  printf("Index:");
  uVar1 = read_long();
  if (uVar1 < 2) {
    realloc(*(void **)(heap + uVar1 * 8),0);
    *(undefined8 *)(heap + uVar1 * 8) = 0;
  }
  else {
    puts("Invalid !");
  }
  return;
}

