typedef struct {
  char* name;
  uint32_t price;
  Product* next;
  Product* back;
} Product;

Product myCart; // 0x804b068

void main(void)
{
  signal(0xe,timeout);
  alarm(0x3c);
  memset(myCart,0,0x10);
  menu();
  handler();
  return;
}

void menu(void)
{
  puts("=== Menu ===");
  printf("%d: Apple Store\n",1);
  printf("%d: Add into your shopping cart\n",2);
  printf("%d: Remove from your shopping cart\n",3);
  printf("%d: List your shopping cart\n",4);
  printf("%d: Checkout\n",5);
  printf("%d: Exit\n",6);
  return;
}


void handler(void)
{
  int iVar1;
  int in_GS_OFFSET;
  char buf [22];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  do {
    printf("> ");
    fflush(stdout);
    my_read(buf,0x15);
    iVar1 = atoi(buf);
    switch(iVar1) {
    default:
      puts("It\'s not a choice! Idiot.");
      break;
    case 1:
      list();
      break;
    case 2:
      add();
      break;
    case 3:
      delete();
      break;
    case 4:
      cart();
      break;
    case 5:
      checkout();
      break;
    case 6:
      puts("Thank You for Your Purchase!");
      if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
  } while( true );
}

void add(void)
{
  int iVar1;
  int in_GS_OFFSET;
  Product *new_product;
  char buf [22]; // -0x22(%ebp)
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  printf("Device Number> ");
  fflush(stdout);
  my_read(buf,0x15);
  iVar1 = atoi(buf);
  switch(iVar1) {
  default:
    puts("Stop doing that. Idiot!");
    goto LAB_08048986;
  case 1:
    new_product = (undefined4 *)create("iPhone 6",199);
    break;
  case 2:
    new_product = (undefined4 *)create("iPhone 6 Plus",299);
    break;
  case 3:
    new_product = (undefined4 *)create("iPad Air 2",499);
    break;
  case 4:
    new_product = (undefined4 *)create("iPad Mini 3",399);
    break;
  case 5:
    new_product = (undefined4 *)create("iPod Touch",199);
  }
  insert(new_product);
  printf("You\'ve put *%s* in your shopping cart.\n",*new_product);
  puts("Brilliant! That\'s an amazing idea.");
LAB_08048986:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


int cart(void)
{
  int in_GS_OFFSET;
  int local_34;
  int total_price;
  Product *curr_product;
  char buf [22]; // -0x22(%ebp)
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_34 = 1;
  total_price = 0;
  printf("Let me check your cart. ok? (y/n) > ");
  fflush(stdout);
  my_read(buf,0x15);
  if (buf[0] == 'y') {
    puts("==== Cart ====");
    for (curr_product = myCart.next; curr_product != (undefined4 *)0x0;
        curr_product = (undefined4 *)curr_product->next) {
      printf("%d: %s - $%d\n",local_34,*curr_product,curr_product->price);
      total_price = total_price + curr_product->price;
      local_34 = local_34 + 1;
    }
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return new_product;
}


void checkout(void)
{
  int in_GS_OFFSET;
  int total_price;
  Product iphone8;      // -0x20(ebp)
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  total_price = cart();
  if (total_price == 0x1c06) {
    puts("*: iPhone 8 - $1");
    asprintf(&iphone8.name,"%s","iPhone 8");
    iphone8.price = 1;
    insert(&iphone8);
    total_price = 0x1c07;
  }
  printf("Total: $%d\n", total_price);
  puts("Want to checkout? Maybe next time!");
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


char ** create(undefined4 param_1,char *param_2)
{
  char **__ptr;
  
  __ptr = (char **)malloc(0x10);
  __ptr[1] = param_2;
  asprintf(__ptr,"%s",param_1);
  __ptr[2] = (char *)0x0;
  __ptr[3] = (char *)0x0;
  return __ptr;
}


void delete(void)
{
  Product* prev;
  Product* next;
  int in_GS_OFFSET;
  int i;
  undefined4 *curr_product;
  char buf[22]; // -0x22(%ebp)
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  i = 1;
  curr_product = myCart.next;
  printf("Item Number> ");
  fflush(stdout);
  my_read(buf, 0x15);
  iVar2 = atoi(buf);
  do {
    if (curr_product == (undefined4 *)0x0) {
LAB_08048a5e:
      if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
    if (i == iVar2) {
      next = curr->next;
      prev = curr->back;
      if (prev != 0) {
        prev->next = next;
      }
      if (next != 0) {
        next->back = prev;
      }
      printf("Remove %d:%s from your shopping cart.\n",i,*curr_product);
      goto LAB_08048a5e;
    }
    i = i + 1;
    curr = curr->next;
  } while( true );
}




void insert(Product* new_product)
{
  Product* product;
  
  for (product = myCart; product->next != 0; product = product->next) {
  }
  product->next = new_product;
  new_product->back = product;
  return;
}


void list(void)
{
  puts("=== Device List ===");
  printf("%d: iPhone 6 - $%d\n",1,199);
  printf("%d: iPhone 6 Plus - $%d\n",2,299);
  printf("%d: iPad Air 2 - $%d\n",3,499);
  printf("%d: iPad Mini 3 - $%d\n",4,399);
  printf("%d: iPod Touch - $%d\n",5,199);
  return;
}


void my_read(void *param_1,size_t param_2)
{
  ssize_t sVar1;
  
  sVar1 = read(0,param_1,param_2);
  if (sVar1 == -1) {
    puts("Input Error.");
  }
  else {
    *(undefined *)((int)param_1 + sVar1) = 0;
  }
  return;
}

