
undefined4 beat(char *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (*param_1 == '\0') {
    puts("You need create the bullet first !");
    uVar1 = 0;
  }
  else {
    puts(">----------- Werewolf -----------<");
    printf(" + NAME : %s\n",param_2[1]);
    printf(" + HP : %d\n",*param_2);
    puts(">--------------------------------<");
    puts("Try to beat it .....");
    usleep(1000000);
    *param_2 = *param_2 - *(int *)(param_1 + 0x30);
    if (*param_2 < 1) {
      puts("Oh ! You win !!");
      uVar1 = 1;
    }
    else {
      puts("Sorry ... It still alive !!");
      uVar1 = 0;
    }
  }
  return uVar1;
}

