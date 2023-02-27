
void calc(void)
{
  int iVar1;
  int in_GS_OFFSET;
  struct {
    int pool_size;
    undefined4 pool_data[100];
  }
  undefined expr_buf[1024];
  int canary;
  
  canary = *(int *)(in_GS_OFFSET + 0x14);
  while( true ) {
    bzero(expr_buf,0x400);
    // get_expr: get STRIPPED expr
    iVar1 = get_expr(expr_buf, 0x400);
    if (iVar1 == 0) break;

    // init_pool: memset the pool
    init_pool(&pool);
    
    // parse_expr
    iVar1 = parse_expr(expr_buf, &pool);
    if (iVar1 != 0) {
      printf("%d\n", pool_data[pool_size + -1]);
      fflush((FILE *)_IO_2_1_stdout_);
    }
  }
  if (canary == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

int get_expr(int param_1,int param_2)
{
  ssize_t sVar1;
  char local_11;
  int local_10;
  
  local_10 = 0;
  while (local_10 < param_2) {
    sVar1 = read(0,&local_11,1);
    if ((sVar1 == -1) || (local_11 == '\n')) break;
    if ((((local_11 == '+') || (((local_11 == '-' || (local_11 == '*')) || (local_11 == '/')))) ||
        (local_11 == '%')) || (('/' < local_11 && (local_11 < ':')))) {
      *(char *)(local_10 + param_1) = local_11;
      local_10 = local_10 + 1;
    }
  }
  *(undefined *)(param_1 + local_10) = 0;
  return local_10;
}


undefined4 parse_expr(void *expr_start, int *pool)
{
  int iVar1;
  char *operand;
  int num;
  undefined4 uVar3;
  size_t num_len;
  int in_GS_OFFSET;
  void *curr_expr_ptr;
  int curr_expr_idx;
  int op_stack_size;
  char op_stack[100]; // -0x70(ebp)
  int canary;
  
  canary = *(int *)(in_GS_OFFSET + 0x14);
  curr_expr_ptr = expr_start;
  op_stack_size = 0;
  
  // parse_expr + 72
  bzero(op_stack, 100);

  // parse_expr + 77
  curr_expr_idx = 0;
  do {
    // if not numeric
    if (9 < (int)*(char *)((int)expr_start + curr_expr_idx) - '0') {
      // atoi() the number
      num_len = (int)expr_start + (curr_expr_idx - (int)curr_expr_ptr);
      num_buf = (char *) malloc(num_len + 1);
      memcpy(num_buf, curr_expr_ptr, num_len);
      num_buf[num_len] = '\0';
      num = strcmp(num_buf,"0");
      if (num == 0) {
        puts("prevent division by zero");
        fflush((FILE *)_IO_2_1_stdout_);
        uVar3 = 0;
        goto return_block;
      }
      num = atoi(num_buf);
      if (0 < num) {
        // parse_expr + 282
        pool->pool_size = pool->pool_size + 1;
        pool->pool_data[pool->pool_size - 1] = num;
      }
      if ((*(char *)((int)expr_buf + curr_expr_idx) != '\0') &&
         (9 < (int)*(char *)((int)expr_buf + curr_expr_idx + 1) - 0x30U)) {
        puts("expression error!");
        fflush((FILE *)_IO_2_1_stdout_);
        uVar3 = 0;
        goto return_block;
      }
      curr_expr_ptr = (void *)((int)expr_buf + curr_expr_idx + 1);
      if (op_stack[op_stack_size] == '\0') {
        op_stack[op_stack_size] = *(char *)((int)expr_buf + curr_expr_idx);
      }
      else {
        switch(*(undefined *)((int)expr_buf + curr_expr_idx)) {
        case '%':
        case '/':
        case '*':
          if ((op_stack[op_stack_size] == '+') || (op_stack[op_stack_size] == '-')) {
            op_stack[op_stack_size + 1] = *(char *)((int)expr_buf + curr_expr_idx);
            op_stack_size = op_stack_size + 1;
          } else {
            eval(pool,(int)op_stack[op_stack_size]);
            op_stack[op_stack_size] = *(char *)((int)expr_buf + curr_expr_idx);
          }
          break;
        default:
          eval(pool,(int)op_stack[op_stack_size]);
          op_stack_size = op_stack_size + -1;
          break;
        case '+':
        case '-':
          eval(pool,(int)op_stack[op_stack_size]);
          op_stack[op_stack_size] = *(char *)((int)expr_buf + curr_expr_idx);
        }
      }
      if (*(char *)((int)expr_buf + curr_expr_idx) == '\0') {
        for (; -1 < op_stack_size; op_stack_size = op_stack_size + -1) {
          eval(pool,(int)op_stack[op_stack_size]);
        }
        uVar3 = 1;
return_block:
        if (canary != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return uVar3;
      }
    }
    curr_expr_idx = curr_expr_idx + 1;
  } while( true );
}


void eval(int *pool,char operator)
{
  int p_size = pool->pool_size;
  int p_data = pool->pool_data;
  if (operator == '+') {
    p_data[p_size-2] = p_data[p_size-2] + p_data[p_size-1];
  }
  else if (operator < ',') {
    if (operator == '*') {
      p_data[p_size-2] = p_data[p_size-2] * p_data[p_size-1];
    }
  }
  else if (operator == '-') {
    p_data[p_size-2] = p_data[p_size-2] - p_data[p_size-1];
  }
  else if (operator == '/') {
    p_data[p_size-2] = p_data[p_size-2] / p_data[p_size-1];
  }
  pool->pool_size = pool->pool_size + -1;
  return;
}


