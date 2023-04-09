
ulong FUN_00101a22(void)

{
  ulong uVar1;
  ulong uVar2;
  long in_FS_OFFSET;
  undefined8 local_1a;
  undefined2 local_12;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_1a = 0;
  local_12 = 0;
  printf("Shellcode index: ");
  fgets((char *)&local_1a,9,stdin);
  uVar1 = strtol((char *)&local_1a,(char **)0x0,10);
  if ((4 < (uint)uVar1) || (uVar2 = uVar1 & 0xffffffff, (&DAT_00104120)[(int)(uint)uVar1] == 0)) {
    puts("Invalid shellcode index!");
    uVar2 = 0xffffffff;
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

