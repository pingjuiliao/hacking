
// 0x401b6d
// We can only overwrite data region
char main(void)
{
  char cVar1;
  int iVar2;
  long in_FS_OFFSET;
  undefined local_28 [24]; // -0x20(%rbp)
  long local_10; // -0x8(%rbp)
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  DAT_004b9330 = DAT_004b9330 + '\x01';
  cVar1 = DAT_004b9330;
  if (DAT_004b9330 == '\x01') {
    write(1,"addr:",5); // 0x446ec0
    read(0,local_28,0x18); // 0x446e20
    iVar2 = atoi64(local_28); // 0x44ee70
    // 0x401bf2: cltq
    iVar2 = dword_to_qword_sign(iVar2);
    write(1,"data:",5);
    read(0,(long)iVar2,0x18);
    cVar1 = '\0';
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    FUN_0044a3e0();
  }
  // 0x401c4c, esp = 0x7fffffffd988
  return cVar1;
}

// Some where after return from main...
// It took so long to find it
// Ghidra helps a lot.
//
// Logic towards finding it:
// we get to arbitrary write once in the main
// so the vulnerable part must happen after it.
// I review instrucion step by step to find the vulnerability
void FUN_00402960(void)
{
  long lVar1;
  
  lVar1 = 1;
  do {
    (*(code *)(&PTR_FUN_004b40f0)[lVar1])();
    lVar1 = lVar1 + -1;
  } while (lVar1 != -1);
  FUN_0048e32c();
  return;
}

