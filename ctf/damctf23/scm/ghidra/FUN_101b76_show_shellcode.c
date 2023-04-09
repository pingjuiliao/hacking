
void FUN_00101b76(void)

{
  uint *puVar1;
  ulong uVar2;
  
  uVar2 = 0;
  do {
    puVar1 = (uint *)(&DAT_00104120)[uVar2];
    if (puVar1 == (uint *)0x0) {
      printf("Shellcode #%d: <empty>\n",uVar2 & 0xffffffff);
    }
    else {
      printf("Shellcode #%d: type=%d, length=%d\n",uVar2 & 0xffffffff,(ulong)puVar1[1],
             (ulong)*puVar1);
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 != 5);
  return;
}

