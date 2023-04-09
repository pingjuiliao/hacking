
uint * FUN_0010149e(void)

{
  uint uVar1;
  uint *__ptr;
  long lVar2;
  void *__buf;
  long in_FS_OFFSET;
  undefined local_58 [16];
  undefined local_48 [16];
  undefined local_38 [16];
  undefined2 local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_58 = ZEXT816(0);
  local_48 = ZEXT816(0);
  local_38 = ZEXT816(0);
  local_28 = 0;
  __ptr = (uint *)malloc(0x10);
  printf("Shellcode type (1=simple, 2=read, 3=write): ");
  fgets(local_58,0x31,stdin);
  lVar2 = strtol(local_58,(char **)0x0,10);
  __ptr[1] = (int)(char)lVar2;
  if ((int)(char)lVar2 - 1U < 3) {
    printf("Size of shellcode: ");
    local_58 = (undefined  [16])0x0;
    local_48 = (undefined  [16])0x0;
    local_38 = (undefined  [16])0x0;
    local_28 = 0;
    fgets(local_58,0x31,stdin);
    lVar2 = strtol(local_58,(char **)0x0,10);
    *__ptr = (uint)lVar2;
    if ((uint)lVar2 - 1 < 99) {
      printf("Shellcode: ");
      uVar1 = *__ptr;
      __buf = malloc((ulong)uVar1);
      *(void **)(__ptr + 2) = __buf;
      read(0,__buf,(ulong)uVar1);
    }
    else {
      puts("Bad size!");
      free(__ptr);
      __ptr = (uint *)0x0;
    }
  }
  else {
    puts("Bad type!");
    free(__ptr);
    __ptr = (uint *)0x0;
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return __ptr;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

