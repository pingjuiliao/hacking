eggshell:
	gcc -m32 -c eggshell.S -o eggshell.o
	gcc -m32 eggshell.o -o eggshell.exe
	objcopy -S -O binary -j .text eggshell.o eggshell.bin
clean:
	rm *.o *.bin *.exe
