
ssize_t read_input(void *param_1,size_t param_2)

{
  ssize_t sVar1;
  
  sVar1 = read(0,param_1,param_2);
  if (sVar1 < 1) {
    puts("read error");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  if (*(char *)((int)param_1 + sVar1 + -1) == '\n') {
    *(undefined *)((int)param_1 + sVar1 + -1) = 0;
  }
  return sVar1;
}

