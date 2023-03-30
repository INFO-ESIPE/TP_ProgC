SP=source/
HD=headers/
BLD=build/
CC=gcc	
CFLAGS=-Wall -ansi -pedantic -pthread 
OBJ=${BLD}main.o ${BLD}taquin.o 
LDFLAGS=-lMLV -lm 
OUT=SuperTaquin

all: ${OBJ}
	${CC} -o ${OUT} ${OBJ} ${CFLAGS} ${LDFLAGS} 

${BLD}main.o: main.c ${HD}taquin.h
	${CC} -c main.c -o ${BLD}main.o ${CFLAGS} 

${BLD}taquin.o: ${SP}taquin.c 
	${CC} -c ${SP}taquin.c -o ${BLD}taquin.o ${CFLAGS} 

clean :
	rm ${BLD}*
	rm ${OUT}

run : ${OBJ}
	${CC} -o ${OUT} ${OBJ} ${CFLAGS} ${LDFLAGS}
	./${OUT} 

