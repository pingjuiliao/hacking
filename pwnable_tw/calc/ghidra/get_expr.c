
int get_expr(int param_1,int param_2)

{
  ssize_t sVar1;
  char local_11;
  int local_10;
  
  local_10 = 0;
  while (local_10 < param_2) {
    sVar1 = read(0,&local_11,1);
    if ((sVar1 == -1) || (local_11 == '\n')) break;
    if ((((local_11 == '+') || (((local_11 == '-' || (local_11 == '*')) || (local_11 == '/')))) ||
        (local_11 == '%')) || (('/' < local_11 && (local_11 < ':')))) {
      *(char *)(local_10 + param_1) = local_11;
      local_10 = local_10 + 1;
    }
  }
  *(undefined *)(param_1 + local_10) = 0;
  return local_10;
}

