CC=gcc
CFLAGS=-m64
all: a
a: a.S
	$(CC) $(CFLAGS) -o $@.o -c $<
	$(CC) $(CFLAGS) -o $@.exe $@.o
clean:
	rm $(wildcard *.o) $(wildcard *.exe)
