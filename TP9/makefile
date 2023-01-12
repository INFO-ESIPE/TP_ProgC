CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDFLAGS=
OBJ=main.o exo1.o exo2.o exo3.o

all: $(OBJ)
	$(CC) -o allocation $(OBJ) $(CFLAGS)

main.o: main.c exo1.h exo2.h exo3.h
	$(CC) -c main.c $(CFLAGS)

exo1.o: exo1.c
	$(CC) -c exo1.c -o exo1.o $(CFLAGS)

exo2.o: exo2.c
	$(CC) -c exo2.c -o exo2.o $(CFLAGS)

exo3.o: exo3.c
	$(CC) -c exo3.c -o exo3.o $(CFLAGS)

run1:
	valgrind ./allocation --exo1 10

run2:
	valgrind ./allocation --exo2 10 15

run3:
	valgrind ./allocation --exo3 quelques arguments 124 45.19

clean: 
	rm -f *.o
	rm -f *~
	rm -f allocation
