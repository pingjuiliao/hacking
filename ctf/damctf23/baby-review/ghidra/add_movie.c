
void add_movie(char *param_1)

{
  char *pcVar1;
  
  puts("Enter your movie link here and I\'ll add it to the list");
  read(0,param_1,300);
  pcVar1 = strstr(param_1,"%n");
  if (pcVar1 != (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  return;
}

