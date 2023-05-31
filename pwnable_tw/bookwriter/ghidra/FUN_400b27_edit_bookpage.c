
void FUN_00400b27(void)

{
  uint uVar1;
  size_t sVar2;
  
  printf("Index of page :");
  uVar1 = FUN_004008cd();
  if (7 < uVar1) {
    puts("out of page:");
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  if (*(long *)(&DAT_006020a0 + (ulong)uVar1 * 8) == 0) {
    puts("Not found !");
  }
  else {
    printf("Content:");
    FUN_00400856(*(undefined8 *)(&DAT_006020a0 + (ulong)uVar1 * 8),
                 *(ulong *)(&DAT_006020e0 + (ulong)uVar1 * 8) & 0xffffffff);
    sVar2 = strlen(*(char **)(&DAT_006020a0 + (ulong)uVar1 * 8));
    *(size_t *)(&DAT_006020e0 + (ulong)uVar1 * 8) = sVar2;
    puts("Done !");
  }
  return;
}

