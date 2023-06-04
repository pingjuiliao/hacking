
void FUN_0010106d(void)

{
  uint uVar1;
  
  printf("Index :");
  uVar1 = FUN_00100ca9();
  if (99 < uVar1) {
    puts("Out of bound !");
                    /* WARNING: Subroutine does not return */
    exit(-2);
  }
  if (*(long *)((ulong)uVar1 * 0x30 + DAT_00302018 + 0x28) == 0) {
    puts("No such heap !");
  }
  else {
    FUN_00100de4((ulong)uVar1 * 0x30 + DAT_00302018);
    puts("Done !");
  }
  return;
}

