
int read_int(void)

{
  int iVar1;
  char local_1c [20];
  ssize_t local_8;
  
  local_8 = read(0,local_1c,0xf);
  if (local_8 < 1) {
    puts("read error");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  iVar1 = atoi(local_1c);
  return iVar1;
}

