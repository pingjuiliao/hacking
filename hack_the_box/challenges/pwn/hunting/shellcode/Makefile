sc:
	gcc -m32 -c sc.S -o sc.o
	gcc -m32 sc.o -o sc.exe
	objcopy -S -O binary -j .text sc.o sc.bin
clean:
	rm *.o *.bin *.exe
