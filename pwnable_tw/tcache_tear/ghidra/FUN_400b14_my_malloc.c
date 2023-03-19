
void FUN_00400b14(void)

{
  ulong __size;
  
  printf("Size:");
  __size = FUN_004009c4();
  if (__size < 0x100) {
    DAT_00602088 = malloc(__size);
    printf("Data:");
    FUN_00400a25(DAT_00602088,(int)__size + -0x10);
    puts("Done !");
  }
  return;
}

