CC=gcc
CFLAGS=-Wall -ansi -pedantic
OBJ=main.o swap.o name_list.o

all: $(OBJ)
	$(CC) -o exe $(OBJ) $(CFLAGS)

main.o: main.c swap.c name_list.c
	$(CC) -c main.c $(CFLAGS)

swap.o: swap.c
	$(CC) -c swap.c -o swap.o $(CFLAGS)
	
name_list.o: name_list.c
	$(CC) -c name_list.c -o name_list.o $(CFLAGS)


clean: 
	rm -f *.o
	rm -f *~
	rm -f allocation
