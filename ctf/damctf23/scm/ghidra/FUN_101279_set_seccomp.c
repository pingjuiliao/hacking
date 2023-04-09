
undefined8 FUN_00101279(char param_1,char param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = seccomp_init(0x80000000);
  uVar3 = 0;
  if (lVar2 != 0) {
    iVar1 = seccomp_rule_add_exact(lVar2,0x7fff0000,0xe7,0);
    uVar3 = 0;
    if (-1 < iVar1) {
      if ((param_1 != '\0') && (iVar1 = seccomp_rule_add_exact(lVar2,0x7fff0000,0,0), iVar1 < 0)) {
        return 0;
      }
      if ((param_2 != '\0') && (iVar1 = seccomp_rule_add_exact(lVar2,0x7fff0000,1,0), iVar1 < 0)) {
        return 0;
      }
      iVar1 = seccomp_load(lVar2);
      uVar3 = 0;
      if (-1 < iVar1) {
        seccomp_release(lVar2);
        uVar3 = 1;
      }
    }
  }
  return uVar3;
}

