.globl main
.type main, @function

main:
	push %rbp;
	mov %rsp, %rbp;
	sub $0x20, %rsp;
	mov $0x81, %rax;
	mov %eax, -0x1c(%rbp);
	mov %al, -0x9(%rbp);
	
	movsbl -0x9(%rbp), %eax;
	cmp %eax, -0x1c(%rbp);
	je shellcode;

	leave;
	ret;


shellcode:
	xor %rdx, %rdx;
	xor %rsi, %rsi;
	movabs $0x0068732f6e69622f, %rdi;
	push %rdi;
	push %rsp;
	pop %rdi;
	mov $0x3b, %rax;
	syscall;
