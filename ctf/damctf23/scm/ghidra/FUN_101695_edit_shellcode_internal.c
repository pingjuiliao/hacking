
undefined4 FUN_00101695(int *param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  ulong uVar4;
  void *__buf;
  long in_FS_OFFSET;
  undefined local_78 [16];
  undefined local_68 [16];
  undefined local_58 [16];
  undefined2 local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_78 = ZEXT816(0);
  local_68 = ZEXT816(0);
  local_58 = ZEXT816(0);
  local_48 = 0;
  uVar3 = 0;
  if (param_1 != (int *)0x0) {
    cVar2 = FUN_0010162a("Do you want to change the shellcode type?");
    if (cVar2 != '\0') {
      printf("Shellcode type (1=simple, 2=read, 3=write): ");
      local_78 = (undefined  [16])0x0;
      local_68 = (undefined  [16])0x0;
      local_58 = (undefined  [16])0x0;
      local_48 = 0;
      fgets(local_78,0x31,stdin);
      uVar4 = strtol(local_78,(char **)0x0,10);
      if (2 < (byte)((char)uVar4 - 1U)) {
        puts("Bad type!");
        uVar3 = 0;
        goto LAB_0010179a;
      }
      printf("Changing type to %d\n",uVar4 & 0xffffffff);
      param_1[1] = (int)uVar4;
    }
    uVar3 = FUN_0010162a("Do you want to change the shellcode?");
    if ((char)uVar3 == '\0') {
      uVar3 = 1;
    }
    else {
      printf("Size of shellcode: ");
      local_78 = (undefined  [16])0x0;
      local_68 = (undefined  [16])0x0;
      local_58 = (undefined  [16])0x0;
      local_48 = 0;
      fgets(local_78,0x31,stdin);
      uVar4 = strtol(local_78,(char **)0x0,10);
      iVar1 = (int)uVar4;
      if (iVar1 - 1U < 99) {
        printf("Shellcode: ");
        __buf = malloc((long)iVar1);
        read(0,__buf,(long)iVar1);
        printf("Changing shellcode to new blob of length %d\n",uVar4 & 0xffffffff);
        free(*(void **)(param_1 + 2));
        *param_1 = iVar1;
        *(void **)(param_1 + 2) = __buf;
      }
      else {
        puts("Bad size!");
        uVar3 = 0;
      }
    }
  }
LAB_0010179a:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

