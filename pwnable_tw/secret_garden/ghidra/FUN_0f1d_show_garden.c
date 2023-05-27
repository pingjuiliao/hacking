
void FUN_00100f1d(void)

{
  long lVar1;
  int *piVar2;
  ulong uVar3;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  uVar3 = 0;
  if (DAT_00302024 == 0) {
    puts("No flower in the garden !");
  }
  else {
    do {
      piVar2 = (int *)(&DAT_00302040)[uVar3];
      if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {
        __printf_chk(1,"Name of the flower[%u] :%s\n",uVar3 & 0xffffffff,*(undefined8 *)(piVar2 + 2)
                    );
        __printf_chk(1,"Color of the flower[%u] :%s\n",uVar3 & 0xffffffff,
                     (&DAT_00302040)[uVar3] + 0x10);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 != 100);
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

