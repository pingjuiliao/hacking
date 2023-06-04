
long read_input(long param_1,undefined4 param_2)

{
  int iVar1;
  long lVar2;
  
  iVar1 = __read_chk(0,param_1,param_2,param_2);
  lVar2 = (long)iVar1;
  if (lVar2 == 0) {
    puts("read error");
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  if (*(char *)(param_1 + lVar2 + -1) == '\n') {
    *(undefined *)(param_1 + lVar2 + -1) = 0;
  }
  return lVar2;
}

