
/* WARNING: Removing unreachable block (ram,0x00402114) */
/* WARNING: Removing unreachable block (ram,0x004023d2) */
/* WARNING: Removing unreachable block (ram,0x00402106) */
/* WARNING: Removing unreachable block (ram,0x004023c4) */
/* WARNING: Removing unreachable block (ram,0x00401f85) */
/* WARNING: Removing unreachable block (ram,0x00401ee4) */
/* WARNING: Removing unreachable block (ram,0x004021af) */
/* WARNING: Removing unreachable block (ram,0x0040215f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00401eb0(code *param_1,int param_2,long param_3,code *param_4,long param_5,long param_6,
                 undefined8 param_7)

{
  undefined8 *puVar1;
  long lVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined8 uVar7;
  int iVar8;
  uint *puVar9;
  int extraout_EDX;
  Elf64_Rela *pEVar10;
  long *plVar11;
  long in_FS_OFFSET;
  undefined auStack_190 [24];
  uint uStack_178;
  long lStack_168;
  undefined8 uStack_100;
  int local_ec;
  long local_e8;
  code *local_e0;
  int local_d0;
  int local_cc;
  int local_c8;
  uint local_c4;
  undefined local_c0 [4];
  undefined local_bc [4];
  undefined local_b8 [8];
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined local_98 [72];
  undefined8 local_50;
  undefined8 local_48;
  
  DAT_004b8798 = 0;
  uStack_100 = 0x401ef8;
  local_ec = param_2;
  local_e8 = param_3;
  local_e0 = param_1;
  FUN_00401a80();
  DAT_004b9da8 = (long *)(local_e8 + 8 + (long)local_ec * 8);
  DAT_004b6ab0 = param_7;
  plVar11 = DAT_004b9da8;
  do {
    lVar2 = *plVar11;
    plVar11 = plVar11 + 1;
  } while (lVar2 != 0);
  uStack_100 = 0x401f30;
  FUN_0044ac60();
  if (DAT_004ba8b8 == (Elf64_Phdr *)0x0) {
    DAT_004ba8b8 = Elf64_Phdr_ARRAY_00400040;
    DAT_004ba8f0 = 8;
  }
  uStack_100 = 0x401f6f;
  FUN_0044b870();
  uStack_100 = 0x401f7b;
  FUN_0044a610(DAT_004b9da8);
  local_d0 = 0;
  puVar3 = (undefined4 *)cpuid_basic_info(0);
  DAT_004b9de4 = *puVar3;
  pEVar10 = (Elf64_Rela *)(ulong)(uint)puVar3[1];
  iVar4 = puVar3[2];
  iVar8 = puVar3[3];
  local_cc = 0;
  if (puVar3[1] != 0x756e6547) goto LAB_004020c0;
  if (iVar8 != 0x6c65746e) goto LAB_004020c0;
  if (iVar4 == 0x49656e69) goto LAB_004023a6;
LAB_00401fb9:
  puVar9 = (uint *)0x0;
  uStack_100 = 0x401fc6;
  FUN_00401c50(0,0,0);
  DAT_004b9de0 = 3;
LAB_00401fcb:
  do {
    if ((DAT_004b9df4 & 0x100) != 0) {
      DAT_004b9e2c = DAT_004b9e2c | 0x4000;
    }
    if ((DAT_004b9df4 & 0x8000) != 0) {
      DAT_004b9e2c = DAT_004b9e2c | 0x8000;
    }
    DAT_004b9e18 = local_d0;
    DAT_004b9e1c = local_cc;
    uStack_100 = 0x40201c;
    FUN_0044abe0(0,local_b8,FUN_0044b900);
    uStack_100 = 0x40202d;
    FUN_0044abe0(0xd,&local_b0,0);
    DAT_004b9e40 = local_b0;
    uStack_100 = 0x40204a;
    FUN_0044abe0(0x15,&local_a8,0);
    DAT_004b9e30 = local_a8;
    uStack_100 = 0x402067;
    FUN_0044abe0(0xe,&local_a0,0);
    DAT_004b9dc8 = 2;
    DAT_004b9e38 = local_a0;
    if (DAT_004b9de0 == 1) {
      if (((DAT_004b9e2c & 0x1000) != 0) && ((DAT_004b9dfc & 0x10000000) != 0)) {
        if ((DAT_004b9dfc & 0x8000000) == 0) {
          puVar9 = (uint *)(ulong)(DAT_004b9dfc & 0x40020000);
          if (((DAT_004b9dfc & 0x40020000) == 0x40020000) && ((int)DAT_004b9dfc < 0)) {
            DAT_004b9dc8 = 6;
          }
        }
        else if ((DAT_004b9dfc & 0x4000000) != 0) {
          DAT_004ba890 = "xeon_phi";
          goto LAB_0040208b;
        }
      }
      if (((((DAT_004b9e2c & 0x480) == 0x480) && ((DAT_004b9dfc & 0x108) == 0x108)) &&
          ((_DAT_004b9e10 & 0x20) != 0)) && ((DAT_004b9df0 & 0xc00000) == 0xc00000)) {
        DAT_004ba890 = "haswell";
      }
    }
LAB_0040208b:
    pEVar10 = Elf64_Rela_ARRAY_00400248;
    while( true ) {
      iVar8 = (int)puVar9;
      if ((Elf64_Rela *)((long)&Elf64_Rela_ARRAY_00400248[0x16].r_addend + 7) < pEVar10)
      goto LAB_0040217e;
      puVar1 = (undefined8 *)pEVar10->r_offset;
      if (*(int *)&pEVar10->r_info != 0x25) break;
      uStack_100 = 0x402097;
      uVar7 = (*(code *)pEVar10->r_addend)();
      pEVar10 = pEVar10 + 1;
      *puVar1 = uVar7;
    }
    uStack_100 = 0x4020c0;
    FUN_00413540();
    iVar4 = extraout_EDX;
LAB_004020c0:
    if (((int)pEVar10 != 0x68747541 || iVar8 != 0x444d4163) || (iVar4 != 0x69746e65))
    goto LAB_00401fb9;
    uStack_100 = 0x402101;
    FUN_00401c50(&local_d0,&local_cc,local_c0,local_bc);
    puVar9 = (uint *)cpuid(0x80000000);
    uVar6 = puVar9[3];
    if (0x80000000 < *puVar9) {
      puVar3 = (undefined4 *)cpuid(0x80000001);
      _DAT_004b9e08 = *puVar3;
      _DAT_004b9e0c = puVar3[1];
      _DAT_004b9e14 = puVar3[2];
      uVar6 = puVar3[3];
      _DAT_004b9e10 = uVar6;
    }
    puVar9 = (uint *)(ulong)uVar6;
    if (((DAT_004b9e2c & 0x40) != 0) && ((_DAT_004b9e10 & 0x10000) != 0)) {
      DAT_004b9e2c = DAT_004b9e2c | 0x100;
    }
    if ((local_d0 == 0x15) && (local_cc - 0x60U < 0x20)) {
      DAT_004b9e2c = DAT_004b9e2c & 0xfffff7ff | 0x12;
    }
    DAT_004b9de0 = 2;
  } while( true );
LAB_0040217e:
  uStack_100 = 0x402183;
  FUN_00402690();
  *(ulong *)(in_FS_OFFSET + 0x28) = *DAT_004b6aa0 & 0xffffffffffffff00;
  if (DAT_004b8798 == 0) {
    uStack_100 = 0x402373;
    uVar6 = FUN_0044c590();
    if ((int)uVar6 < 0) {
      uStack_100 = 0x4024df;
      FUN_00413540("FATAL: cannot determine kernel version\n");
      iVar4 = FUN_004476e0(0,1);
      if (((iVar4 == -1) && (*(int *)(in_FS_OFFSET + -0x40) == 9)) &&
         (((iVar4 = FUN_00447810("/dev/full",0x20001,0), iVar4 != 0 ||
           ((iVar4 = FUN_00446cb0(1,0,auStack_190), iVar4 != 0 || ((uStack_178 & 0xf000) != 0x2000))
           )) || (lStack_168 != 0x107)))) {
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      iVar4 = FUN_004476e0(1,1);
      if (((iVar4 == -1) && (*(int *)(in_FS_OFFSET + -0x40) == 9)) &&
         ((iVar4 = FUN_00447810("/dev/null",0x20000,0), iVar4 != 1 ||
          (((iVar4 = FUN_00446cb0(1,1,auStack_190), iVar4 != 0 || ((uStack_178 & 0xf000) != 0x2000))
           || (lStack_168 != 0x103)))))) {
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      iVar4 = FUN_004476e0(2,1);
      if (((iVar4 == -1) && (*(int *)(in_FS_OFFSET + -0x40) == 9)) &&
         (((iVar4 = FUN_00447810("/dev/null",0x20000,0), iVar4 != 2 ||
           ((iVar4 = FUN_00446cb0(1,2,auStack_190), iVar4 != 0 || ((uStack_178 & 0xf000) != 0x2000))
           )) || (lStack_168 != 0x103)))) {
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      return;
    }
    if ((DAT_004ba910 == 0) || (uVar6 < DAT_004ba910)) {
      DAT_004ba910 = uVar6;
    }
    if ((int)uVar6 < 0x30200) {
      uStack_100 = 0x4023a6;
      FUN_00413540("FATAL: kernel too old\n");
LAB_004023a6:
      uStack_100 = 0x4023bf;
      FUN_00401c50(&local_d0,&local_cc,&local_c8,&local_c4);
      puVar9 = (uint *)cpuid(0x80000000);
      uVar6 = puVar9[3];
      if (0x80000000 < *puVar9) {
        puVar3 = (undefined4 *)cpuid(0x80000001);
        _DAT_004b9e08 = *puVar3;
        _DAT_004b9e0c = puVar3[1];
        _DAT_004b9e14 = puVar3[2];
        uVar6 = puVar3[3];
        _DAT_004b9e10 = uVar6;
      }
      puVar9 = (uint *)(ulong)uVar6;
      if (local_d0 == 6) {
        local_cc = local_cc + local_c8;
        puVar9 = &switchD_00402448::switchdataD_0048f0d0;
        switch(local_cc) {
        default:
          if ((DAT_004b9df0 & 0x10000000) == 0) break;
        case 0x1a:
        case 0x1e:
        case 0x1f:
        case 0x25:
        case 0x2c:
        case 0x2e:
        case 0x2f:
          DAT_004b9e2c = DAT_004b9e2c | 0x40031;
          break;
        case 0x1c:
        case 0x26:
          DAT_004b9e2c = DAT_004b9e2c | 4;
          break;
        case 0x37:
        case 0x4a:
        case 0x4c:
        case 0x4d:
        case 0x57:
        case 0x5a:
        case 0x5c:
        case 0x5d:
        case 0x5f:
          DAT_004b9e2c = DAT_004b9e2c | 0x40230;
          break;
        case 0x3f:
          if (3 < local_c4) break;
        case 0x3c:
        case 0x45:
        case 0x46:
          DAT_004b9dfc = DAT_004b9dfc & 0xfffff7ff;
        }
      }
      uVar6 = DAT_004b9e2c | 0x100000;
      if ((DAT_004b9dfc & 0x8000000) != 0) {
        uVar6 = DAT_004b9e2c | 0x20000;
      }
      DAT_004b9de0 = 1;
      DAT_004b9e2c = uVar6;
      goto LAB_00401fcb;
    }
  }
  *(ulong *)(in_FS_OFFSET + 0x30) = DAT_004b6aa0[1];
  if (param_6 != 0) {
    uStack_100 = 0x4021d9;
    FUN_0040fbc0(param_6,0,0);
  }
  uStack_100 = 0x4021ee;
  FUN_0044c6a0(local_ec,local_e8,DAT_004b9da8);
  if (param_5 != 0) {
    uStack_100 = 0x4021ff;
    FUN_0040fbc0(param_5,0,0);
  }
  if (DAT_004b6ab8 != 0) {
    uStack_100 = 0x402369;
    FUN_004024e0();
  }
  if (param_4 != (code *)0x0) {
    uStack_100 = 0x402223;
    // 0x402221
    (*param_4)(local_ec,local_e8,DAT_004b9da8);
  }
  uStack_100 = 0x40222c;
  FUN_0044a4a0(0,0);
  uStack_100 = 0x402236;
  iVar4 = FUN_0040ed50(local_98);
  if (iVar4 != 0) goto LAB_00402288;
  local_50 = *(undefined8 *)(in_FS_OFFSET + 0x300);
  local_48 = *(undefined8 *)(in_FS_OFFSET + 0x2f8);
  *(undefined **)(in_FS_OFFSET + 0x300) = local_98;
  uStack_100 = 0x402281;
  // 0x40227f: main
  uVar5 = (*local_e0)(local_ec,local_e8,DAT_004b9da8);
  while( true ) {
    uStack_100 = 0x402288;
    FUN_0040f940(uVar5);
LAB_00402288:
    uStack_100 = 0x40228d;
    func_0x00000000();
    LOCK();
    _SUB_00000000 = _SUB_00000000 + -1;
    if (_SUB_00000000 != 0) break;
    uVar5 = 0;
  }
  do {
    syscall();
  } while( true );
}

