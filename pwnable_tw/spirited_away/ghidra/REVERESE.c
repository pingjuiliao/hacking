
void main(void)
{
  puts("Thanks for watching Spirited Away!");
  puts("Please leave some comments to help us improve our next movie!");
  fflush(stdout);
  survey();
  return;
}

// 0x804860d
void survey(void)
{
  char local_ec [56]; // $ebp - 0xe8
  size_t heap_buf_size; // $ebp - 0xb0
  size_t stack_buf_reason_size; // $ebp - 0xac
  undefined comment_buf_size [0x50]; // $ebp - 0xa8
  undefined4 age; // $ebp -0x58
  void *heap_buf; // $ebp - 0x54
  undefined stack_buf_reason [0x50]; // $ebp - 0x50
  
  heap_buf_size = 0x3c;
  stack_buf_reason_size = 0x50;
  do {
    memset(comment_buf_size,0,0x50);
    heap_buf = malloc(0x3c);
    printf("\nPlease enter your name: ");
    fflush(stdout);
    read(0,heap_buf,heap_buf_size);
    printf("Please enter your age: ");
    fflush(stdout);
    __isoc99_scanf(&DAT_080489d2,&age);
    printf("Why did you came to see this movie? ");
    fflush(stdout);
    read(0,stack_buf_reason,stack_buf_reason_size);
    fflush(stdout);
    printf("Please enter your comment: ");
    fflush(stdout);
    read(0,comment_buf_size,heap_buf_size);
    cnt = cnt + 1;
    printf("Name: %s\n",heap_buf);
    printf("Age: %d\n",age);
    printf("Reason: %s\n",stack_buf_reason);
    printf("Comment: %s\n\n",comment_buf_size);
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
    free(heap_buf);
  } while( true );
}

