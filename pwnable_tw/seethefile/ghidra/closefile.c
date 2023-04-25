
void closefile(void)

{
  if (fp == (FILE *)0x0) {
    puts("Nothing need to close");
  }
  else {
    fclose(fp);
  }
  fp = (FILE *)0x0;
  return;
}

