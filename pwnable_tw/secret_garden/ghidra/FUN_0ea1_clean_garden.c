
void FUN_00100ea1(void)

{
  long lVar1;
  int *__ptr;
  int **ppiVar2;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  ppiVar2 = (int **)&DAT_00302040;
  do {
    __ptr = *ppiVar2;
    if ((__ptr != (int *)0x0) && (*__ptr == 0)) {
      free(__ptr);
      *ppiVar2 = (int *)0x0;
      DAT_00302024 = DAT_00302024 + -1;
    }
    ppiVar2 = ppiVar2 + 1;
  } while (ppiVar2 != (int **)&_end);
  puts("Done!");
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

