
void FUN_00100e6c(void)

{
  int iVar1;
  int local_14;
  
  local_14 = 0;
  while( true ) {
    if (99 < local_14) {
      puts("Fulled !!");
      return;
    }
    if (*(long *)((long)local_14 * 0x30 + DAT_00302018 + 0x28) == 0) break;
    local_14 = local_14 + 1;
  }
  printf("Size of heart : ");
  iVar1 = FUN_00100ca9();
  if (0x100 < (ulong)(long)iVar1) {
    puts("Too big !");
    return;
  }
  FUN_00100d27(DAT_00302018 + (long)local_14 * 0x30,(long)iVar1);
  puts("Done !");
  return;
}

