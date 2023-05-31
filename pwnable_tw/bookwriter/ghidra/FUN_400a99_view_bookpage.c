
void FUN_00400a99(void)

{
  uint uVar1;
  
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
    printf("Page #%u \n",(ulong)uVar1);
    printf("Content :\n%s\n",*(undefined8 *)(&DAT_006020a0 + (ulong)uVar1 * 8));
  }
  return;
}

