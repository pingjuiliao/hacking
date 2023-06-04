CC=gcc
CFLAGS=-m32 -no-pie
all: ldr shellcode
ldr: ldr.c
	$(CC) $(CFLAGS) -o $@.exe $<
shellcode: shellcode.S
	$(CC) $(CFLAGS) -o $@.o -c $<
	$(CC) $(CFLAGS) -o $@.exe $@.o
	objcopy -S -O binary -j .text $@.o $@.bin
clean:
	rm $(wildcard *.o) $(wildcard *.bin) $(wildcard *.exe)
