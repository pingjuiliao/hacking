
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

uint FUN_000113d0(void)
{
  int iVar1;
  undefined4 local_1c [2];
  undefined4 local_14;
  uint local_10;
  
  local_14 = open("/dev/urandom",0);
  read(local_14,local_1c,8);
  close(local_14);
  srand(local_1c[0]);
  local_10 = 0;
  while (((int)local_10 < 0x60000000 || (0xf7000000 < local_10))) {
    iVar1 = rand();
    local_10 = iVar1 << 0x10;
  }
  return local_10;
}


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
  int secret_region;
  undefined4 local_14;
  undefined *local_10;
  
  local_10 = &stack0x00000004;
  local_24 = 0x11486;
  local_14 = FUN_000113d0();
  pcStack_2c = exit;
  uStack_30 = 0xe;
  signal();
  uStack_30 = 10;
  alarm();
  // pcStack_2c = (code *)0x0;
  // uStack_30 = 0xffffffff;
  secret_region = mmap(local_14,0x1000,3,0x31, 0xffffffff, 0x0);
  puVar2 = (undefined4 *)auStack_20;
  if (secret_region == -1) {
    uStack_30 = 0xffffffff;
    exit();
    puVar2 = &uStack_30;
  }
  /* *(char **)((int)puVar2 + -0xc) = s_HTB_XXXXXXXXXXXXXXXXXXXXXXXXXXXX_00014020;
  *(int *)((int)puVar2 + -0x10) = secret_region;
  *(undefined4 *)((int)puVar2 + -0x14) = 0x114eb;
  strcpy();*/
  strcpy(secret_region, DAT_4020);
  /**(undefined4 *)((int)puVar2 + -8) = 0x25;
  *(undefined4 *)((int)puVar2 + -0xc) = 0;
  *(char **)((int)puVar2 + -0x10) = s_HTB_XXXXXXXXXXXXXXXXXXXXXXXXXXXX_00014020;
  *(undefined4 *)((int)puVar2 + -0x14) = 0x11501;
  memset()*/
  memset(DAT_4020, 0, 0x25);
  secret_region = 0;
  *(undefined4 *)((int)puVar2 + -4) = 0x11510;
  FUN_0001133d();
  /**(undefined4 *)((int)puVar2 + -0xc) = 0;
  *(undefined4 *)((int)puVar2 + -0x10) = 0xffffffff;
  *(undefined4 *)((int)puVar2 + -0x14) = 0x21;
  *(undefined4 *)((int)puVar2 + -0x18) = 7;
  *(undefined4 *)((int)puVar2 + -0x1c) = 0x1000;
  *(undefined4 *)((int)puVar2 + -0x20) = 0;
  *(undefined4 *)((int)puVar2 + -0x24) = 0x11527;
  local_1c = (code *)mmap();*/
  shellcode = mmap(0x0, 0x1000, 0x7, 0x21, 0xffffffff, 0x0);

  /**(undefined4 *)((int)puVar2 + -8) = 0x3c;
  *(code **)((int)puVar2 + -0xc) = local_1c;
  *(undefined4 *)((int)puVar2 + -0x10) = 0;
  *(undefined4 *)((int)puVar2 + -0x14) = 0x1153c;
  read();*/
  read(0, shellcode, 0x3c);
  /**(undefined4 *)((int)puVar2 + 0xc) = 0;
  pcVar1 = local_1c;
  *(undefined4 *)((int)puVar2 + -4) = 0x1154c;
  (*pcVar1)();*/
  (*shellcode)();
  return 0;
}

