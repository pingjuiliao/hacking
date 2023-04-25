
int openfile(void)

{
  int iVar1;
  char *pcVar2;
  
  if (fp == (FILE *)0x0) {
    memset(magicbuf,0,400);
    printf("What do you want to see :");
    __isoc99_scanf(&DAT_08048c03,filename);
    pcVar2 = strstr(filename,"flag");
    if (pcVar2 != (char *)0x0) {
      puts("Danger !");
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    fp = fopen(filename,"r");
    if (fp == (FILE *)0x0) {
      iVar1 = puts("Open failed");
    }
    else {
      iVar1 = puts("Open Successful");
    }
  }
  else {
    puts("You need to close the file first");
    iVar1 = 0;
  }
  return iVar1;
}

