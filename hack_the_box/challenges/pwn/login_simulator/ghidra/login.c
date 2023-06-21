
bool _login(char *param_1,int param_2)

{
  int iVar1;
  long in_FS_OFFSET;
  char local_a8 [152];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  printf("{i} Username: ");
  getInput(local_a8,param_2);
  iVar1 = strncmp(local_a8,param_1,(long)param_2);
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1 == 0;
}

