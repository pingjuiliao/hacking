
undefined4 is_printable(char *param_1)

{
  size_t sVar1;
  uint local_10;
  
  local_10 = 0;
  while( true ) {
    sVar1 = strlen(param_1);
    if (sVar1 <= local_10) {
      return 1;
    }
    if ((param_1[local_10] < ' ') || (param_1[local_10] == '\x7f')) break;
    local_10 = local_10 + 1;
  }
  return 0;
}

