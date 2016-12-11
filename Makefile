run:
	gcc -c init.c createDisk.c main.c get.c read.c
	gcc -g init.o createDisk.o main.o get.o read.o -lm
	./a.out vfs.bin
clean:
	rm a.out *.o
	rm *.bin
