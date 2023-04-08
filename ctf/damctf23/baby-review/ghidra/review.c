
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

