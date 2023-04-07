SP=src/
HD=include/
BLD=bin/
CC=gcc	
CFLAGS=-Wall -ansi -pedantic
OBJ=${BLD}main.o ${BLD}taquin.o ${BLD}data.o  ${BLD}menu.o
LDFLAGS=-lMLV -lm 
OUT=SuperTaquin

all: ${OBJ}
	${CC} -o ${OUT} ${OBJ} ${CFLAGS} ${LDFLAGS} 

${BLD}main.o: main.c ${HD}taquin.h
	${CC} -c main.c -o ${BLD}main.o ${CFLAGS} 

${BLD}taquin.o: ${SP}taquin.c 
	${CC} -c ${SP}taquin.c -o ${BLD}taquin.o ${CFLAGS} 

${BLD}data.o: ${SP}data.c 
	${CC} -c ${SP}data.c -o ${BLD}data.o ${CFLAGS} 

${BLD}menu.o: ${SP}menu.c 
	${CC} -c ${SP}menu.c -o ${BLD}menu.o ${CFLAGS} 


clean :
	rm ${BLD}*
	rm ${OUT}

run : ${OBJ}
	${CC} -o ${OUT} ${OBJ} ${CFLAGS} ${LDFLAGS}
	./${OUT} 

rebuild :
	make clean
	make run