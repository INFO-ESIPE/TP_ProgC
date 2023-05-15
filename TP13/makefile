SP=src/
HD=include/
BLD=bin/
CC=gcc	
CFLAGS=-Wall -ansi -pedantic
OBJ=${BLD}main.o ${BLD}dame.o ${BLD}interface.o
LDFLAGS= -lm -lMLV
OUT=counter

all: ${OBJ}
	${CC} -o ${OUT} ${OBJ} ${CFLAGS} ${LDFLAGS} 

${BLD}main.o: ${SP}main.c ${SP}dame.c ${SP}interface.c
	${CC} -c ${SP}main.c -o ${BLD}main.o ${CFLAGS} 

${BLD}dame.o: ${SP}dame.c 
	${CC} -c ${SP}dame.c -o ${BLD}dame.o ${CFLAGS} 

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