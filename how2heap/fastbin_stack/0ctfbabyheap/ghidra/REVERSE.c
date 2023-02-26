
typedef ObjectData {
  uint64_t is_allocated;
  size_t size;
  void* heap_buf;
} Object;


undefined8 main(void)
{
  undefined8 object_pool;
  int operation; // stol()
  

  // object_pool = (Object *) malloc(sizeof(Object) * 0xf)
  object_pool = FUN_00100b70();
  do {
    FUN_00100cf4(); // print_prompt
    operation = get_integer();
    switch(operation) {
    case 1:
      Allocate(object_pool);
      break;
    case 2:
      Fill(object_pool);
      break;
    case 3:
      Free(object_pool);
      break;
    case 4:
      Dump(object_pool);
      break;
    case 5:
      return 0;
    }
  } while( true );
}


void Allocate(long object_pool)
{
  void *chunk_data;
  uint alloca_id;
  int chunk_size;
  
  alloca_id = 0;
  while( true ) {
    if (0xf < (int)alloca_id) {
      return;
    }
    if (*(int *)(object_pool + (long)(int)alloca_id * 0x18) == 0) break;
    alloca_id = alloca_id + 1;
  }
  printf("Size: ");
  chunk_size = get_integer();
  if (chunk_size < 1) {
    return;
  }
  if (0x1000 < chunk_size) {
    chunk_size = 0x1000;
  }
  chunk_data = calloc((long)chunk_size,1);
  if (chunk_data != (void *)0x0) {
    *(undefined4 *)(object_pool + (long)(int)alloca_id * 0x18) = 1;
    *(long *)((long)(int)alloca_id * 0x18 + object_pool + 8) = (long)chunk_size;
    *(void **)((long)(int)alloca_id * 0x18 + object_pool + 0x10) = chunk_data;
    printf("Allocate Index %d\n",(ulong)alloca_id);
    return;
  }
                    /* WARNING: Subroutine does not return */
  exit(-1);
}


void Fill(long object_pool)
{
  int obj_index;
  int iVar2;
  
  printf("Index: ");
  obj_index = get_integer();
  if (((-1 < obj_index) && (obj_index < 0x10)) && (*(int *)(object_pool + (long)obj_index * 0x18) == 1)) {
    printf("Size: ");
    iVar2 = get_integer();
    if (0 < iVar2) {
      printf("Content: ");
      FUN_001011b2(*(undefined8 *)(object_pool + (long)obj_index * 0x18 + 0x10),(long)iVar2);
    }
  }
  return;
}


void Free(long object_pool)
{
  int obj_index;
  
  printf("Index: ");
  obj_index = get_integer();
  if (((-1 < obj_index) && (obj_index < 0x10)) && (*(int *)(object_pool + (long)obj_index * 0x18) == 1)) {
    *(undefined4 *)(object_pool + (long)obj_index * 0x18) = 0;
    *(undefined8 *)(object_pool + (long)obj_index * 0x18 + 8) = 0;
    free(*(void **)(object_pool + (long)obj_index * 0x18 + 0x10));
    *(undefined8 *)(object_pool + (long)obj_index * 0x18 + 0x10) = 0;
  }
  return;
}


void Dump(long object_pool)
{
  int obj_index;
  
  printf("Index: ");
  obj_index = get_integer();
  if (((-1 < obj_index) && (obj_index < 0x10)) && (*(int *)(object_pool + (long)obj_index * 0x18) == 1)) {
    puts("Content: ");
    safe_write(*(undefined8 *)(object_pool + (long)obj_index * 0x18 + 0x10),
                 *(undefined8 *)(object_pool + (long)obj_index * 0x18 + 8));
    puts("");
  }
  return;
}


ulong safe_write(long buf, ulong buf_size)
{
  ssize_t num_written;
  int *piVar2;
  ulong total_num_written;
  
  total_num_written = 0;
  do {
    while( true ) {
      if (buf_size <= total_num_written) {
        return total_num_written;
      }
      num_written = write(1,(void *)(buf + total_num_written),buf_size - total_num_written);
      if (num_written < 1) break;
      total_num_written = total_num_written + num_written;
    }
    piVar2 = __errno_location();
  } while ((*piVar2 == 0xb) || (piVar2 = __errno_location(), *piVar2 == 4));
  return total_num_written;
}


void get_integer(void)
{
  long in_FS_OFFSET;
  char buf[8];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  safe_read(&buf,8);
  %rax = atol(buf);
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return %rax;
}


ulong safe_read(long buf_addr,long buf_size)
{
  int *p_unknown;
  ulong ret_val;
  long in_FS_OFFSET;
  char char_input
  ulong total_num_read;
  ssize_t num_read;
  long canary;
  
  canary = *(long *)(in_FS_OFFSET + 0x28);
  if (buf_size == 0) {
    ret_val = 0;
  }
  else {
    total_num_read = 0;
    do {
      while( true ) {
        if (buf_size - 1U <= total_num_read) goto safe_read_exit;
        num_read = read(0, &char_input, 1);
        if (num_read < 1) break;
        if (char_input == '\n') goto safe_read_exit;
        *(char *)(buf_addr + total_num_read) = char_input;
        total_num_read = total_num_read + 1;
      }
      p_unknown = __errno_location();
    } while ((*p_unknown == 0xb) || (p_unknown = __errno_location(), *p_unknown == 4));

safe_read_exit:
    *(undefined *)(total_num_read + buf_addr) = 0;
    ret_val = total_num_read;
  }
  if (canary == *(long *)(in_FS_OFFSET + 0x28)) {
    return ret_val;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


