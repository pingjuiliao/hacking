
void create_bullet(char *param_1)

{
  size_t sVar1;
  
  if (*param_1 == '\0') {
    printf("Give me your description of bullet :",0);
    read_input(param_1,0x30);
    sVar1 = strlen(param_1);
    printf("Your power is : %u\n",sVar1);
    *(size_t *)(param_1 + 0x30) = sVar1;
    puts("Good luck !!");
  }
  else {
    puts("You have been created the Bullet !");
  }
  return;
}

