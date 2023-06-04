
void FUN_00100c8d(void)

{
  ulong __size;
  void *pvVar1;
  int local_14;
  
  local_14 = 0;
  while( true ) {
    if (0xf < local_14) {
      puts("You can\'t allocate anymore !");
      return;
    }
    if (*(long *)(&DAT_00302040 + (long)local_14 * 8) == 0) break;
    local_14 = local_14 + 1;
  }
  printf("Size :");
  __size = FUN_00100b49();
  if (0x78 < __size) {
    return;
  }
  pvVar1 = malloc(__size);
  *(void **)(&DAT_00302040 + (long)local_14 * 8) = pvVar1;
  if (*(long *)(&DAT_00302040 + (long)local_14 * 8) != 0) {
    printf("Data :");
    FUN_00100baa(*(undefined8 *)(&DAT_00302040 + (long)local_14 * 8),__size & 0xffffffff);
    return;
  }
  puts("Error!");
                    /* WARNING: Subroutine does not return */
  _exit(-1);
}

