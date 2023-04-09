
void FUN_00101bde(void)

{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_00101a22();
  if (iVar2 != -1) {
    cVar1 = FUN_001018a4((&DAT_00104120)[iVar2]);
    if (cVar1 != '\0') {
      puts("Shellcode deleted");
    }
    (&DAT_00104120)[iVar2] = 0;
  }
  return;
}

