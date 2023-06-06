CC=gcc
CFLAGS=-m32 -no-pie
all: shellcode shellcode_only
shellcode: shellcode.S
	$(CC) $(CFLAGS) -c shellcode.S -o shellcode.o
	$(CC) $(CFLAGS) shellcode.o -o shellcode.exe
shellcode_only: shellcode.S
	$(CC) $(CFLAGS) -DSHELLCODE_ONLY -o $@.o -c $<
	objcopy -S -O binary -j .text $@.o shellcode.bin
clean:
	rm *.o *.bin *.exe
