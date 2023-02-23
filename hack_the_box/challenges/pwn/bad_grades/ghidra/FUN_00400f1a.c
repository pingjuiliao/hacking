
void FUN_00400f1a(void)

{
  long in_FS_OFFSET;
  int local_2c;
  uint local_28 [4];
  undefined4 local_18;
  undefined8 local_10;
  
  local_10 = *(undefined8 *)(in_FS_OFFSET + 0x28);
  local_28[0] = 2;
  local_28[1] = 4;
  local_28[2] = 1;
  local_28[3] = 3;
  local_18 = 0;
  puts("\nYour grades were: ");
  for (local_2c = 0; local_2c < 5; local_2c = local_2c + 1) {
    printf("%d\n",(ulong)local_28[local_2c]);
  }
  printf("\nYou need to try ");
  FUN_00400acb("HARDER","magenta","underline");
  puts("!");
                    /* WARNING: Subroutine does not return */
  exit(0x22);
}

