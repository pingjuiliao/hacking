
void getInput(long param_1,int param_2)

{
  ssize_t sVar1;
  long in_FS_OFFSET;
  char local_12;
  char local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_11 = '\0';
  do {
    if ((param_2 <= local_11) || (sVar1 = read(0,&local_12,1), (int)sVar1 < 1))
    goto code_r0x0010137f;
    if (local_12 != ' ') {
      if (local_12 == '\n') {
code_r0x0010137f:
        if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
          return;
        }
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      *(char *)(local_11 + param_1) = local_12;
    }
    local_11 = local_11 + '\x01';
  } while( true );
}

