
void FUN_00100def(char *param_1)

{
  int iVar1;
  size_t __n;
  char local_88 [128];
  
  printf("Your passowrd :");
  FUN_00100ca0(local_88,0x7f);
  __n = strlen(local_88);
  iVar1 = strncmp(local_88,param_1,__n);
  if (iVar1 == 0) {
    DAT_00302014 = 1;
    puts("Login Success !");
  }
  else {
    puts("Failed !");
  }
  return;
}

