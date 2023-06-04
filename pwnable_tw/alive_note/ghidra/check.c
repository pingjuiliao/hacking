
undefined4 check(char *param_1)

{
  ushort **ppuVar1;
  size_t sVar2;
  uint local_10;
  
  local_10 = 0;
  while( true ) {
    sVar2 = strlen(param_1);
    if (sVar2 <= local_10) {
      return 1;
    }
    if ((param_1[local_10] != ' ') &&
       (ppuVar1 = __ctype_b_loc(), ((*ppuVar1)[param_1[local_10]] & 8) == 0)) break;
    local_10 = local_10 + 1;
  }
  return 0;
}

