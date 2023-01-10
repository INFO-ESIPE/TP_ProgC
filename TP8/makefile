CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDFLAGS=
OBJ=main.o syracuse.o syracuse_cache.o

all: $(OBJ)
	$(CC) -o syracuse $(OBJ) $(CFLAGS)

main.o: main.c syracuse.h syracuse_cache.h
	$(CC) -c main.c $(CFLAGS)

syracuse_cache.o: syracuse_cache.c syracuse.h
	$(CC) -c syracuse_cache.c $(CFLAGS)

syracuse.o: syracuse.c syracuse_cache.h
	$(CC) -c syracuse.c $(CFLAGS)

run:
	./syracuse --test_cache

run_it:
	./syracuse --syracuse_iterative 27

clean: 
	rm -f *.o
	rm -f *~
	rm -f syracuse
