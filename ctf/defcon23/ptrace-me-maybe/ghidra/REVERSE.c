
undefined8 main(EVP_PKEY_CTX *param_1)

{
  __pid_t __pid;
  int *piVar1;
  long lVar2;
  long in_FS_OFFSET;
  uint local_38;
  uint local_34;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  long local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  init(param_1);
  local_34 = fork();
  if (local_34 == 0) {
    ptrace(PTRACE_TRACEME,0,0,0);
    __pid = getpid();
    kill(__pid,0x13);
  }
  else {
    ptrace(PTRACE_ATTACH,(ulong)local_34,0,0);
    do {
      waitpid(local_34,(int *)&local_38,0);
    } while ((local_38 & 0xff) != 0x7f);
    do {
      local_30 = read_int("What ptrace request do you want to send?");
      local_28 = read_int("What address do you want?");
      local_20 = read_int("What do you want copied into data?");
      piVar1 = __errno_location();
      *piVar1 = 0;
      local_18 = ptrace((__ptrace_request)local_30,(ulong)local_34,local_28,local_20);
      printf("ptrace returned 0x%lx\n",local_18);
      piVar1 = __errno_location();
      if (*piVar1 != 0) {
        perror("ptrace error");
      }
      lVar2 = read_int("Do another (0/1)?");
    } while (lVar2 != 0);
    ptrace(PTRACE_DETACH,(ulong)local_34,0,0);
    waitpid(local_34,(int *)&local_38,0);
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


undefined8 read_int(char *param_1)

{
  long in_FS_OFFSET;
  undefined8 local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  puts(param_1);
  __isoc99_scanf(&DAT_00102008,&local_18);
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_18;
}

