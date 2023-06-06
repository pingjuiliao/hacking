
undefined4 menu(void)

{
  undefined4 local_c;
  
  puts("1. Record toxin");
  puts("2. Edit existing toxin record");
  puts("3. Drink toxin for testing");
  puts("4. Search for toxin record");
  puts("Enter your lab code.");
  printf("> ");
  __isoc99_scanf(&DAT_00102100,&local_c);
  return local_c;
}

