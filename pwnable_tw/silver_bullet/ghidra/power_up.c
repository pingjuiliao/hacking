
void power_up(char *param_1)

{
  size_t sVar1;
  char local_38 [48];
  int local_8;
  
  local_8 = 0;
  memset(local_38,0,0x30);
  if (*param_1 == '\0') {
    puts("You need create the bullet first !");
  }
  else if (*(uint *)(param_1 + 0x30) < 0x30) {
    printf("Give me your another description of bullet :");
    read_input(local_38,0x30 - *(int *)(param_1 + 0x30));
    strncat(param_1,local_38,0x30 - *(int *)(param_1 + 0x30));
    sVar1 = strlen(local_38);
    local_8 = *(int *)(param_1 + 0x30) + sVar1;
    printf("Your new power is : %u\n",local_8);
    *(int *)(param_1 + 0x30) = local_8;
    puts("Enjoy it !");
  }
  else {
    puts("You can\'t power up any more !");
  }
  return;
}

