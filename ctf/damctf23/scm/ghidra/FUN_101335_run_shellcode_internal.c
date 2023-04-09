
void FUN_00101335(uint *param_1)

{
  uint uVar1;
  char cVar2;
  __pid_t _Var3;
  undefined8 *__dest;
  ulong uVar4;
  undefined8 *puVar5;
  long in_FS_OFFSET;
  byte bVar6;
  uint local_24;
  long local_20;
  
  bVar6 = 0;
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  printf("Running shellcode...");
  __dest = (undefined8 *)mmap((void *)0x0,0x1000,7,0x21,-1,0);
  *__dest = 0xc3c3c3c3c3c3c3c3;
  __dest[0x1ff] = 0xc3c3c3c3c3c3c3c3;
  puVar5 = (undefined8 *)((ulong)(__dest + 1) & 0xfffffffffffffff8);
  for (uVar4 = (ulong)(((int)__dest - (int)(undefined8 *)((ulong)(__dest + 1) & 0xfffffffffffffff8))
                       + 0x1000U >> 3); uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar5 = 0xc3c3c3c3c3c3c3c3;
    puVar5 = puVar5 + (ulong)bVar6 * -2 + 1;
  }
  memcpy(__dest,*(void **)(param_1 + 2),(ulong)*param_1);
  _Var3 = fork();
  if (_Var3 != 0) {
    wait(&local_24);
    puts("done!");
    printf("Execution finished with status code %d\n",(ulong)local_24);
    if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  close(2);
  if ((param_1[1] == 3) || (close(1), param_1[1] != 2)) {
    close(0);
    uVar1 = param_1[1];
    if (uVar1 == 3) {
      cVar2 = FUN_00101279(0,1);
      goto joined_r0x00101408;
    }
    if ((int)uVar1 < 4) {
      if (uVar1 == 1) {
        cVar2 = FUN_00101279(0,0);
        goto joined_r0x00101408;
      }
      if (uVar1 == 2) goto LAB_0010141c;
    }
  }
  else {
LAB_0010141c:
    cVar2 = FUN_00101279(1,0);
joined_r0x00101408:
    if (cVar2 == '\0') goto LAB_00101438;
  }
  (*(code *)__dest)();
LAB_00101438:
                    /* WARNING: Subroutine does not return */
  exit(0);
}

