
void writefile(void)

{
  char *pcVar1;
  
  pcVar1 = strstr(filename,"flag");
  if (pcVar1 == (char *)0x0) {
    pcVar1 = strstr(magicbuf,"FLAG");
    if (pcVar1 == (char *)0x0) {
      pcVar1 = strchr(magicbuf,0x7d);
      if (pcVar1 == (char *)0x0) {
        puts(magicbuf);
        return;
      }
    }
  }
  puts("you can\'t see it");
                    /* WARNING: Subroutine does not return */
  exit(1);
}

