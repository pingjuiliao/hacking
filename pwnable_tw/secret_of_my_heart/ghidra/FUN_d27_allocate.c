
void FUN_00100d27(size_t *param_1,size_t param_2)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = param_2;
  printf("Name of heart :");
  FUN_00100c38(param_1 + 1,0x20);
  pvVar2 = malloc(param_2);
  param_1[5] = (size_t)pvVar2;
  if (param_1[5] == 0) {
    puts("Allocate Error !");
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  printf("secret of my heart :");
  iVar1 = FUN_00100c38(param_1[5],param_2 & 0xffffffff);
  *(undefined *)((long)iVar1 + param_1[5]) = 0;
  return;
}

