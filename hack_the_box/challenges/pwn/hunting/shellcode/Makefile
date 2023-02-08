orw:
	gcc -m32 -c orw.S -o orw.o
	gcc -m32 orw.o -o orw.exe
	objcopy -S -O binary -j .text orw.o orw.bin
clean:
	rm *.o *.bin *.exe
