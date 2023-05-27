
void FUN_00100c32(void)

{
  int iVar1;
  undefined8 *puVar2;
  void *__buf;
  long *plVar3;
  uint uVar4;
  long in_FS_OFFSET;
  uint local_24;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_24 = 0;
  if (DAT_00302024 < 100) {
    puVar2 = (undefined8 *)malloc(0x28);
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    __printf_chk(1,"Length of the name :");
    iVar1 = __isoc99_scanf(&DAT_0010121c,&local_24);
    if (iVar1 == -1) {
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    __buf = malloc((ulong)local_24);
    if (__buf == (void *)0x0) {
      puts("Alloca error !!");
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    __printf_chk(1,"The name of flower :");
    read(0,__buf,(ulong)local_24);
    puVar2[1] = __buf;
    __printf_chk(1,"The color of the flower :");
    __isoc99_scanf(&DAT_0010125e,puVar2 + 2);
    *(undefined4 *)puVar2 = 1;
    if (DAT_00302040 == 0) {
      uVar4 = 0;
LAB_00100d75:
      (&DAT_00302040)[uVar4] = (long)puVar2;
    }
    else {
      plVar3 = &DAT_00302048;
      uVar4 = 1;
      do {
        if (*plVar3 == 0) goto LAB_00100d75;
        uVar4 = uVar4 + 1;
        plVar3 = plVar3 + 1;
      } while (uVar4 != 100);
    }
    DAT_00302024 = DAT_00302024 + 1;
    puts("Successful !");
  }
  else {
    puts("The garden is overflow");
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

