
char FUN_00401b6d(void)

{
  char cVar1;
  int iVar2;
  long in_FS_OFFSET;
  undefined local_28 [24];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  DAT_004b9330 = DAT_004b9330 + '\x01';
  cVar1 = DAT_004b9330;
  if (DAT_004b9330 == '\x01') {
    FUN_00446ec0(1,"addr:",5);
    FUN_00446e20(0,local_28,0x18);
    iVar2 = FUN_0040ee70(local_28);
    FUN_00446ec0(1,"data:",5);
    FUN_00446e20(0,(long)iVar2,0x18);
    cVar1 = '\0';
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    FUN_0044a3e0();
  }
  return cVar1;
}

