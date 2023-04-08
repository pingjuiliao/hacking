
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

