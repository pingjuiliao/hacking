
void add_movie(char *param_1)

{
  char *pcVar1;
  
  puts("Enter your movie link here and I\'ll add it to the list");
  read(0,param_1,300);
  pcVar1 = strstr(param_1,"%n");
  if (pcVar1 != (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  return;
}


void load_countries(void)

{
  char *pcVar1;
  char local_88 [112];
  char *local_18;
  FILE *local_10;
  
  local_10 = fopen("countries.txt","r");
  if (local_10 == (FILE *)0x0) {
    puts("Failed to open countries.txt");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  while( true ) {
    pcVar1 = fgets(local_88,100,local_10);
    if (pcVar1 == (char *)0x0) break;
    local_18 = strchr(local_88,0x2c);
    if (local_18 != (char *)0x0) {
      *local_18 = '\0';
      strcpy(countries + (long)num_countries * 100,local_88);
      strcpy(countries + (long)num_countries * 100 + 0x32,local_18 + 1);
      num_countries = num_countries + 1;
    }
  }
  fclose(local_10);
  return;
}


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


void menu(void)

{
  undefined local_158 [303];
  char local_29;
  undefined local_28 [32];
  
  do {
    puts("What would you like to do?");
    puts("1. Read a book?");
    puts("2. Watch a movie?");
    puts("3. Review a book/movie");
    puts("4. Exit");
    __isoc99_scanf(&DAT_0010228e,&local_29);
    getchar();
    switch(local_29) {
    case '1':
      read_book();
      break;
    case '2':
      watch_movie(local_158);
      break;
    case '3':
      review();
      break;
    case '4':
      puts("Sad to see you go.");
      puts("Could I get your name for my records?");
      read(0,local_28,0x30);
      return;
    case '5':
      add_movie(local_158);
      break;
    default:
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
  } while( true );
}


void review(void)

{
  undefined local_438 [1008];
  undefined local_48 [64];
  
  puts("What is the name of the book/movie you would like to review?");
  read(0,local_48,0x3b);
  puts("Okay, write your review below:");
  read(0,local_438,1000);
  puts("Thanks! I\'ll make sure to take note of this review.");
  return;
}


void watch_movie(char *param_1)

{
  puts(&DAT_00102078);
  puts("https://www.youtube.com/watch?v=2bGvWEfLUsc");
  puts("https://www.youtube.com/watch?v=0u1oUsPWWjM");
  puts("https://www.youtube.com/watch?v=dQw4w9WgXcQ");
  puts("https://www.youtube.com/watch?v=Icx4xul9LEE");
  printf(param_1);
  return;
}

