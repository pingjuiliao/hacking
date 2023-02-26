
ulong FUN_0010130f(long param_1,ulong param_2)

{
  ssize_t sVar1;
  int *piVar2;
  ulong local_18;
  
  local_18 = 0;
  do {
    while( true ) {
      if (param_2 <= local_18) {
        return local_18;
      }
      sVar1 = write(1,(void *)(param_1 + local_18),param_2 - local_18);
      if (sVar1 < 1) break;
      local_18 = local_18 + sVar1;
    }
    piVar2 = __errno_location();
  } while ((*piVar2 == 0xb) || (piVar2 = __errno_location(), *piVar2 == 4));
  return local_18;
}

