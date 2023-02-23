
void FUN_00400fd5(void)

{
  long in_FS_OFFSET;
  int local_128;
  int local_124;
  double local_120;
  double local_118 [33];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_120 = 0.0;
  FUN_00400acb("Number of grades: ",&DAT_004012d8,&DAT_00401304);
  __isoc99_scanf(&DAT_0040137e,&local_128);
  for (local_124 = 0; local_124 < local_128; local_124 = local_124 + 1) {
    printf("Grade [%d]: ",(ulong)(local_124 + 1));
    __isoc99_scanf(&DAT_0040138e,local_118 + local_124);
    local_120 = local_118[local_124] + local_120;
  }
  printf("Your new average is: %.2f\n",local_120 / (double)local_128);
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

