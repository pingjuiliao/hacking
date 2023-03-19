
void FUN_00400948(void)

{
  setvbuf(stdin,(char *)0x0,2,0);
  setvbuf(stdout,(char *)0x0,2,0);
  setvbuf(stderr,(char *)0x0,2,0);
  signal(0xe,FUN_00400927);
  alarm(0x3c);
  return;
}

