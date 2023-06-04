
void FUN_00100f3c(void)

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
    printf("Index : %d\n",(ulong)uVar1);
    printf("Size : %lu\n",*(undefined8 *)((ulong)uVar1 * 0x30 + DAT_00302018));
    printf("Name : %s\n",(ulong)uVar1 * 0x30 + DAT_00302018 + 8);
    printf("Secret : %s\n",*(undefined8 *)((ulong)uVar1 * 0x30 + DAT_00302018 + 0x28));
  }
  return;
}

