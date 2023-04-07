all: pop_shell shellcode
pop_shell: pop_shell.S
	$(CC) -m32 pop_shell.S -no-pie -o pop_shell.exe
shellcode: pop_shell.S
	$(CC) -m32 -DSHELLCODE_ONLY -c pop_shell.S -o shellcode.o
	objcopy -S -O binary -j .text shellcode.o shellcode.bin
clean:
	rm $(wildcard *.o) $(wildcard *.exe) $(wildcard *.bin)
