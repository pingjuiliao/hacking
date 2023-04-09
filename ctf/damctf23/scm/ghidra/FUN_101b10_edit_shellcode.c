
void FUN_00101b10(void)

{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_00101a22();
  if (iVar2 != -1) {
    cVar1 = FUN_00101695((&DAT_00104120)[iVar2]);
    if (cVar1 != '\0') {
      puts("Shellcode edited");
    }
  }
  return;
}

