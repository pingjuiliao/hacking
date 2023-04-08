
void load_countries(void)

{
  char *pcVar1;
  char local_88 [112];
  char *local_18;
  FILE *local_10;
  
  local_10 = fopen("countries.txt","r");
  if (local_10 == (FILE *)0x0) {
    puts("Failed to open countries.txt");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  while( true ) {
    pcVar1 = fgets(local_88,100,local_10);
    if (pcVar1 == (char *)0x0) break;
    local_18 = strchr(local_88,0x2c);
    if (local_18 != (char *)0x0) {
      *local_18 = '\0';
      strcpy(countries + (long)num_countries * 100,local_88);
      strcpy(countries + (long)num_countries * 100 + 0x32,local_18 + 1);
      num_countries = num_countries + 1;
    }
  }
  fclose(local_10);
  return;
}

