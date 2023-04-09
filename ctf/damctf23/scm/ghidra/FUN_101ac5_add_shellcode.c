
void FUN_00101ac5(void)

{
  int iVar1;
  long lVar2;
  
  iVar1 = FUN_001019ff();
  if (iVar1 == -1) {
    puts("Too many shellcodes!");
  }
  else {
    lVar2 = FUN_0010149e();
    if (lVar2 != 0) {
      (&DAT_00104120)[iVar1] = lVar2;
      puts("Shellcode saved");
    }
  }
  return;
}

