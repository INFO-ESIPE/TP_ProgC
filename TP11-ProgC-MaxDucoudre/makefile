SP=src/
HD=include/
BLD=bin/
CC=gcc	
CFLAGS=-Wall -ansi
OBJ=${BLD}main.o ${BLD}taquin.o ${BLD}interface.o
LDFLAGS=-lMLV -lm 
OUT=SuperTaquin

all: ${OBJ}
	${CC} -o ${OUT} ${OBJ} ${CFLAGS} ${LDFLAGS} 

${BLD}main.o: ${SP}main.c ${HD}taquin.h
	${CC} -c ${SP}main.c -o ${BLD}main.o ${CFLAGS} 

${BLD}taquin.o: ${SP}taquin.c 
	${CC} -c ${SP}taquin.c -o ${BLD}taquin.o ${CFLAGS} 

${BLD}interface.o: ${SP}interface.c
	${CC} -c ${SP}interface.c -o ${BLD}interface.o ${CFLAGS}

clean :
	rm ${BLD}*
	rm ${OUT}

run : ${OBJ}
	${CC} -o ${OUT} ${OBJ} ${CFLAGS} ${LDFLAGS}
	./${OUT} 

rebuild :
	make clean
	make run