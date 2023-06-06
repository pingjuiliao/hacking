
void main(void)

{
  int iVar1;
  
  setvbuf(stdout,(char *)0x0,2,0);
  setvbuf(stderr,(char *)0x0,2,0);
  setvbuf(stdin,(char *)0x0,2,0);
  puts(
      "Welcome to Toxin, a low-capacity lab designed to store, record and keep track of chemical toxins."
      );
LAB_00101223:
  while (iVar1 = menu(), iVar1 == 4) {
    search_toxin();
  }
  if (iVar1 < 5) {
    if (iVar1 == 3) {
      drink_toxin();
      goto LAB_00101223;
    }
    if (iVar1 < 4) {
      if (iVar1 == 1) {
        add_toxin();
      }
      else {
        if (iVar1 != 2) goto LAB_00101286;
        edit_toxin();
      }
      goto LAB_00101223;
    }
  }
LAB_00101286:
  puts("Lab code not implemented.");
  goto LAB_00101223;
}

