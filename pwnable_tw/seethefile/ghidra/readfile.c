
void readfile(void)

{
  size_t sVar1;
  
  memset(magicbuf,0,400);
  if (fp == (FILE *)0x0) {
    puts("You need to open a file first");
  }
  else {
    sVar1 = fread(magicbuf,399,1,fp);
    if (sVar1 != 0) {
      puts("Read Successful");
    }
  }
  return;
}

