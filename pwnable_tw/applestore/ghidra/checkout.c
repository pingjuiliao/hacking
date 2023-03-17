
void checkout(void)

{
  int in_GS_OFFSET;
  int local_2c;
  char *local_24;
  undefined4 local_20;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_2c = cart();
  if (local_2c == 0x1c06) {
    puts("*: iPhone 8 - $1");
    asprintf(&local_24,"%s","iPhone 8");
    local_20 = 1;
    insert(&local_24);
    local_2c = 0x1c07;
  }
  printf("Total: $%d\n",local_2c);
  puts("Want to checkout? Maybe next time!");
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

