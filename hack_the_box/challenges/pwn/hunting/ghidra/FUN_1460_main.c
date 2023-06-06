
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_00011460(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  undefined4 uStack_30;
  code *pcStack_2c;
  undefined4 local_24;
  undefined auStack_20 [4];
  code *local_1c;
  int local_18;
  undefined4 local_14;
  undefined *local_10;
  
  local_10 = &stack0x00000004;
  local_24 = 0x11486;
  local_14 = FUN_000113d0();
  pcStack_2c = exit;
  uStack_30 = 0xe;
  FUN_00011140();
  uStack_30 = 10;
  FUN_00011150();
  pcStack_2c = (code *)0x0;
  uStack_30 = 0xffffffff;
  local_18 = FUN_000111a0(local_14,0x1000,3,0x31);
  puVar2 = (undefined4 *)auStack_20;
  if (local_18 == -1) {
    uStack_30 = 0xffffffff;
    FUN_00011120();
    puVar2 = &uStack_30;
  }
  *(char **)((int)puVar2 + -0xc) = s_HTB_XXXXXXXXXXXXXXXXXXXXXXXXXXXX_00014020;
  *(int *)((int)puVar2 + -0x10) = local_18;
  *(undefined4 *)((int)puVar2 + -0x14) = 0x114eb;
  FUN_00011170();
  *(undefined4 *)((int)puVar2 + -8) = 0x25;
  *(undefined4 *)((int)puVar2 + -0xc) = 0;
  *(char **)((int)puVar2 + -0x10) = s_HTB_XXXXXXXXXXXXXXXXXXXXXXXXXXXX_00014020;
  *(undefined4 *)((int)puVar2 + -0x14) = 0x11501;
  FUN_000111c0();
  local_18 = 0;
  *(undefined4 *)((int)puVar2 + -4) = 0x11510;
  FUN_0001133d();
  *(undefined4 *)((int)puVar2 + -0xc) = 0;
  *(undefined4 *)((int)puVar2 + -0x10) = 0xffffffff;
  *(undefined4 *)((int)puVar2 + -0x14) = 0x21;
  *(undefined4 *)((int)puVar2 + -0x18) = 7;
  *(undefined4 *)((int)puVar2 + -0x1c) = 0x1000;
  *(undefined4 *)((int)puVar2 + -0x20) = 0;
  *(undefined4 *)((int)puVar2 + -0x24) = 0x11527;
  local_1c = (code *)FUN_000111a0();
  *(undefined4 *)((int)puVar2 + -8) = 0x3c;
  *(code **)((int)puVar2 + -0xc) = local_1c;
  *(undefined4 *)((int)puVar2 + -0x10) = 0;
  *(undefined4 *)((int)puVar2 + -0x14) = 0x1153c;
  FUN_00011130();
  *(undefined4 *)((int)puVar2 + 0xc) = 0;
  pcVar1 = local_1c;
  *(undefined4 *)((int)puVar2 + -4) = 0x1154c;
  (*pcVar1)();
  return 0;
}

