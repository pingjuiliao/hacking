
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00100ac1(void)

{
  setvbuf(_stdin,(char *)0x0,2,0);
  setvbuf(_stdout,(char *)0x0,2,0);
  setvbuf(_stderr,(char *)0x0,2,0);
  signal(0xe,FUN_00100aa0);
  alarm(0x3c);
  return;
}

