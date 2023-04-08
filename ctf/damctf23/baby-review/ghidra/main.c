
undefined8 main(void)

{
  int iVar1;
  time_t tVar2;
  size_t sVar3;
  char local_58 [64];
  undefined1 *local_18;
  int local_c;
  
  tVar2 = time((time_t *)0x0);
  srand((uint)tVar2);
  load_countries();
  puts("Alright I need to prove you\'re human so lets do some geography");
  local_c = rand();
  local_c = local_c % num_countries;
  local_18 = countries + (long)local_c * 100;
  printf("What is the capital of %s?\n",local_18);
  fgets(local_58,0x32,stdin);
  sVar3 = strcspn(local_58,"\r\n");
  local_58[sVar3] = '\n';
  iVar1 = strcmp(local_58,local_18 + 0x32);
  if (iVar1 == 0) {
    puts("Correct!");
    puts("Alright I\'ll let you through");
    menu();
    return 0;
  }
  printf("Incorrect. The capital of %s is %s.\n",local_18,local_18 + 0x32);
                    /* WARNING: Subroutine does not return */
  exit(0);
}

