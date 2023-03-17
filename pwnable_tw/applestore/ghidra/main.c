
void main(void)

{
  signal(0xe,timeout);
  alarm(0x3c);
  memset(myCart,0,0x10);
  menu();
  handler();
  return;
}

