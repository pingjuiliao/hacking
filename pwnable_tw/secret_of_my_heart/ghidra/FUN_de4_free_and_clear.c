
void FUN_00100de4(undefined8 *param_1)

{
  *param_1 = 0;
  memset(param_1 + 1,0,0x20);
  free((void *)param_1[5]);
  param_1[5] = 0;
  return;
}

