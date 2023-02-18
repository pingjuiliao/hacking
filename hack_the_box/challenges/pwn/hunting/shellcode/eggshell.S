.globl main
.type main, @function

main:
	// call *%eax will be the way to call this shellcode
	push %eax;
	pop %esi;
	mov $0x7fffffff, %ebx;
	xor %ecx, %ecx;
	
	mov $0x8, %edx;
	push %ecx;
	push $0x68732f6e;
	push $0x69622f2f;
	push %esp;
	pop %ecx;
	mov $0x1, %ebx;	
	cmp %eax, %ebx;
	jle write_flag;
	mov $0x4, %edx;
write_flag:
	mov $0x4, %eax;
	int $0x80;
  ret;
