
void survey(void)

{
  char local_ec [56];
  size_t local_b4;
  size_t local_b0;
  undefined local_ac [80];
  undefined4 local_5c;
  void *local_58;
  undefined auStack84 [80];
  
  local_b4 = 0x3c;
  local_b0 = 0x50;
  do {
    memset(local_ac,0,0x50);
    local_58 = malloc(0x3c);
    printf("\nPlease enter your name: ");
    fflush(stdout);
    read(0,local_58,local_b4);
    printf("Please enter your age: ");
    fflush(stdout);
    __isoc99_scanf(&DAT_080489d2,&local_5c);
    printf("Why did you came to see this movie? ");
    fflush(stdout);
    read(0,auStack84,local_b0);
    fflush(stdout);
    printf("Please enter your comment: ");
    fflush(stdout);
    read(0,local_ac,local_b4);
    cnt = cnt + 1;
    printf("Name: %s\n",local_58);
    printf("Age: %d\n",local_5c);
    printf("Reason: %s\n",auStack84);
    printf("Comment: %s\n\n",local_ac);
    fflush(stdout);
    sprintf(local_ec,"%d comment so far. We will review them as soon as we can",cnt);
    puts(local_ec);
    puts("");
    fflush(stdout);
    if (199 < cnt) {
      puts("200 comments is enough!");
      fflush(stdout);
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    while( true ) {
      printf("Would you like to leave another comment? <y/n>: ");
      fflush(stdout);
      read(0,&choice,3);
      if (((char)choice == 'Y') || ((char)choice == 'y')) break;
      if (((char)choice == 'N') || ((char)choice == 'n')) {
        puts("Bye!");
        fflush(stdout);
        return;
      }
      puts("Wrong choice.");
      fflush(stdout);
    }
    free(local_58);
  } while( true );
}

