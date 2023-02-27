
undefined4 parse_expr(void *param_1,int *param_2)

{
  int iVar1;
  char *__s1;
  int iVar2;
  undefined4 uVar3;
  size_t __n;
  int in_GS_OFFSET;
  void *local_8c;
  int local_88;
  int local_84;
  char local_74 [100];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_8c = param_1;
  local_84 = 0;
  bzero(local_74,100);
  local_88 = 0;
  do {
    if (9 < (int)*(char *)((int)param_1 + local_88) - 0x30U) {
      __n = (int)param_1 + (local_88 - (int)local_8c);
      __s1 = (char *)malloc(__n + 1);
      memcpy(__s1,local_8c,__n);
      __s1[__n] = '\0';
      iVar2 = strcmp(__s1,"0");
      if (iVar2 == 0) {
        puts("prevent division by zero");
        fflush((FILE *)_IO_2_1_stdout_);
        uVar3 = 0;
        goto LAB_0804935f;
      }
      iVar2 = atoi(__s1);
      if (0 < iVar2) {
        iVar1 = *param_2;
        *param_2 = iVar1 + 1;
        param_2[iVar1 + 1] = iVar2;
      }
      if ((*(char *)((int)param_1 + local_88) != '\0') &&
         (9 < (int)*(char *)((int)param_1 + local_88 + 1) - 0x30U)) {
        puts("expression error!");
        fflush((FILE *)_IO_2_1_stdout_);
        uVar3 = 0;
        goto LAB_0804935f;
      }
      local_8c = (void *)((int)param_1 + local_88 + 1);
      if (local_74[local_84] == '\0') {
        local_74[local_84] = *(char *)((int)param_1 + local_88);
      }
      else {
        switch(*(undefined *)((int)param_1 + local_88)) {
        case 0x25:
        case 0x2a:
        case 0x2f:
          if ((local_74[local_84] == '+') || (local_74[local_84] == '-')) {
            local_74[local_84 + 1] = *(char *)((int)param_1 + local_88);
            local_84 = local_84 + 1;
          }
          else {
            eval(param_2,(int)local_74[local_84]);
            local_74[local_84] = *(char *)((int)param_1 + local_88);
          }
          break;
        default:
          eval(param_2,(int)local_74[local_84]);
          local_84 = local_84 + -1;
          break;
        case 0x2b:
        case 0x2d:
          eval(param_2,(int)local_74[local_84]);
          local_74[local_84] = *(char *)((int)param_1 + local_88);
        }
      }
      if (*(char *)((int)param_1 + local_88) == '\0') {
        for (; -1 < local_84; local_84 = local_84 + -1) {
          eval(param_2,(int)local_74[local_84]);
        }
        uVar3 = 1;
LAB_0804935f:
        if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return uVar3;
      }
    }
    local_88 = local_88 + 1;
  } while( true );
}

