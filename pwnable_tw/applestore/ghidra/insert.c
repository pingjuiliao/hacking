
void insert(int param_1)

{
  undefined1 *local_8;
  
  for (local_8 = myCart; *(int *)(local_8 + 8) != 0; local_8 = *(undefined1 **)(local_8 + 8)) {
  }
  *(int *)(local_8 + 8) = param_1;
  *(undefined1 **)(param_1 + 0xc) = local_8;
  return;
}

