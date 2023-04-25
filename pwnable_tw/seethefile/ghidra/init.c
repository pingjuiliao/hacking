
int init(EVP_PKEY_CTX *ctx)

{
  uint uVar1;
  
  setvbuf(stdout,(char *)0x0,2,0);
  signal(0xe,handler);
  uVar1 = alarm(0x3c);
  return uVar1;
}

