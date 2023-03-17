
void add(void)

{
  int iVar1;
  int in_GS_OFFSET;
  undefined4 *local_30;
  char local_26 [22];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  printf("Device Number> ");
  fflush(stdout);
  my_read(local_26,0x15);
  iVar1 = atoi(local_26);
  switch(iVar1) {
  default:
    puts("Stop doing that. Idiot!");
    goto LAB_08048986;
  case 1:
    local_30 = (undefined4 *)create("iPhone 6",199);
    break;
  case 2:
    local_30 = (undefined4 *)create("iPhone 6 Plus",299);
    break;
  case 3:
    local_30 = (undefined4 *)create("iPad Air 2",499);
    break;
  case 4:
    local_30 = (undefined4 *)create("iPad Mini 3",399);
    break;
  case 5:
    local_30 = (undefined4 *)create("iPod Touch",199);
  }
  insert(local_30);
  printf("You\'ve put *%s* in your shopping cart.\n",*local_30);
  puts("Brilliant! That\'s an amazing idea.");
LAB_08048986:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

