
int cart(void)

{
  int in_GS_OFFSET;
  int local_34;
  int local_30;
  undefined4 *local_2c;
  char local_26 [22];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_34 = 1;
  local_30 = 0;
  printf("Let me check your cart. ok? (y/n) > ");
  fflush(stdout);
  my_read(local_26,0x15);
  if (local_26[0] == 'y') {
    puts("==== Cart ====");
    for (local_2c = myCart._8_4_; local_2c != (undefined4 *)0x0;
        local_2c = (undefined4 *)local_2c[2]) {
      printf("%d: %s - $%d\n",local_34,*local_2c,local_2c[1]);
      local_30 = local_30 + local_2c[1];
      local_34 = local_34 + 1;
    }
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_30;
}

