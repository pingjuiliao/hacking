
ulong FUN_00100c38(void *param_1,uint param_2)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = read(0,param_1,(ulong)param_2);
  iVar1 = (int)uVar2;
  if (iVar1 < 1) {
    puts("read error");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  if (*(char *)((long)param_1 + (long)iVar1 + -1) == '\n') {
    *(undefined *)((long)param_1 + (long)iVar1 + -1) = 0;
  }
  return uVar2 & 0xffffffff;
}

