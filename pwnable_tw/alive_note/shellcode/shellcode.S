.globl main
.type main, @function


main:
	mov $main, %eax;
	nop;
	nop;
	# .byte 0x0, 0x31; # je, 0x30	
	push $0x3;
	pop %esi;
	xor $0x30, %si;
	xor %esi, (%eax, %esi, 1)
	xor %edx, (%eax, %edx, 1)
	xor %ebx, (%eax, %ebx, 1)
	xor %ecx, (%eax, %ecx, 1)
	xor %edi, (%eax, %edi, 1)
	xor %ebp, (%eax, %ebp, 1)
		

# valide
#xor (%edi, %esi, 1), %esi;
	#xor (%edx, %esi, 1), %esi;
	#xor (%eax, %esi, 1), %esi;
	
#xor (%edx, %eax, 1), %eax; 	
#	xor (%ecx, %eax, 1), %eax; 	
#	xor (%eax, %ecx, 1), %edx; 	
#	xor (%eax, %ecx, 1), %edx; 	
#	xor (%eax, %edx, 1), %ecx; 	
#	xor (%ecx, %edx, 1), %ecx; 	
#	xor (%edx, %ecx, 1), %ecx; 	
#	xor (%edx, %ecx, 1), %edx; 	
#	xor (%ecx, %eax, 1), %eax;
#	xor (%edx, %eax, 1), %eax;
#	xor (%eax, %ecx, 1), %eax;
#	xor (%eax, %edx, 1), %eax;
#	xor (%edx, %ecx, 1), %edx; 	
	# .byte 0x0, 0x31; # je, 0x30	
