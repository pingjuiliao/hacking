
void drink_toxin(void)

{
  int local_c;
  
  puts("This is dangerous testing, I\'m warning you!");
  printf("Toxin index: ");
  __isoc99_scanf(&DAT_00102100,&local_c);
  if (((local_c < 0) || (2 < local_c)) || (*(long *)(toxins + (long)local_c * 8) == 0)) {
    puts("Invalid toxin index.");
  }
  else if (toxinfreed == 0) {
    toxinfreed = 1;
    free(*(void **)(toxins + (long)local_c * 8));
  }
  else {
    puts("You can only drink toxins once, they\'re way too poisonous to try again.");
  }
  return;
}

