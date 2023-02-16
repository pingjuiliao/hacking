.globl main
.type main, @function

main:
	xor %edx, %edx;
	mov $0x1, %ecx;
	mov $0x16, %ebx;
	mov $0xac, %eax;
	int $0x80;


