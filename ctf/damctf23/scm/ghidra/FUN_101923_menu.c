
void FUN_00101923(void)

{
  long in_FS_OFFSET;
  undefined8 local_1a;
  undefined2 local_12;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_1a = 0;
  local_12 = 0;
  puts("\nPlease choose an operation:");
  puts("1) Add a new shellcode");
  puts("2) Edit a shellcode");
  puts("3) Execute a shellcode");
  puts("4) Show your shellcodes");
  puts("5) Delete a shellcodes");
  puts("6) Exit");
  puts("7) Mystery");
  printf("\nChoice: ");
  fgets((char *)&local_1a,9,stdin);
  strtol((char *)&local_1a,(char **)0x0,10);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

