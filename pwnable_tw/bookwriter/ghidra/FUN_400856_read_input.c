
int FUN_00400856(long param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = __read_chk(0,param_1,param_2,param_2);
  if (iVar1 < 0) {
    puts("read error");
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  if (*(char *)(param_1 + (long)iVar1 + -1) == '\n') {
    *(undefined *)(param_1 + (long)iVar1 + -1) = 0;
  }
  return iVar1;
}

