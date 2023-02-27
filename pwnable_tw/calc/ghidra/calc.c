
void calc(void)

{
  int iVar1;
  int in_GS_OFFSET;
  int local_5a4;
  undefined4 auStack_5a0 [100];
  undefined local_410 [1024];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  while( true ) {
    bzero(local_410,0x400);
    iVar1 = get_expr(local_410,0x400);
    if (iVar1 == 0) break;
    init_pool(&local_5a4);
    iVar1 = parse_expr(local_410,&local_5a4);
    if (iVar1 != 0) {
      printf("%d\n",auStack_5a0[local_5a4 + -1]);
      fflush((FILE *)_IO_2_1_stdout_);
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

