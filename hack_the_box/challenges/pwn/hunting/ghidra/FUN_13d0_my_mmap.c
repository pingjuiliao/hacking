
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

uint FUN_000113d0(void)

{
  int iVar1;
  undefined4 local_1c [2];
  undefined4 local_14;
  uint local_10;
  
  local_14 = FUN_00011180("/dev/urandom",0);
  FUN_00011130(local_14,local_1c,8);
  FUN_000111f0(local_14);
  FUN_00011190(local_1c[0]);
  local_10 = 0;
  while (((int)local_10 < 0x60000000 || (0xf7000000 < local_10))) {
    iVar1 = FUN_000111e0();
    local_10 = iVar1 << 0x10;
  }
  return local_10;
}

