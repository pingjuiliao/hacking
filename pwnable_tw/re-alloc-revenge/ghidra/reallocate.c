
void reallocate(void)

{
  ulong uVar1;
  ulong __size;
  void *pvVar2;
  
  printf("Index:");
  uVar1 = read_long();
  if ((uVar1 < 2) && (*(long *)(heap + uVar1 * 8) != 0)) {
    printf("Size:");
    __size = read_long();
    if (__size < 0x79) {
      pvVar2 = realloc(*(void **)(heap + uVar1 * 8),__size);
      if (pvVar2 == (void *)0x0) {
        puts("alloc error");
      }
      else {
        *(void **)(heap + uVar1 * 8) = pvVar2;
        printf("Data:");
        read_input(*(undefined8 *)(heap + uVar1 * 8),__size & 0xffffffff);
      }
    }
    else {
      puts("Too large!");
    }
  }
  else {
    puts("Invalid !");
  }
  return;
}

