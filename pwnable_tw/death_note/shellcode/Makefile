shellcode: shellcode.S
	gcc -m32 -c shellcode.S -no-pie -o shellcode.o
	gcc -m32 shellcode.o -no-pie -o shellcode.exe
	objcopy -S -O binary -j .text shellcode.o shellcode.bin
clean:
	rm $(wildcard *.o) $(wildcard *.exe) $(wildcard *.bin)
