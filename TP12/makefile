SP=src/
HD=include/
BLD=bin/
CC=gcc	
CFLAGS=-Wall -ansi -pedantic
OBJ=${BLD}main.o ${BLD}counter.o ${BLD}hash.o
LDFLAGS= -lm 
OUT=counter

all: ${OBJ}
	${CC} -o ${OUT} ${OBJ} ${CFLAGS} ${LDFLAGS} 

${BLD}main.o: ${SP}main.c ${SP}counter.c ${SP}hash.c
	${CC} -c ${SP}main.c -o ${BLD}main.o ${CFLAGS} 

${BLD}counter.o: ${SP}counter.c 
	${CC} -c ${SP}counter.c -o ${BLD}counter.o ${CFLAGS} 

${BLD}hash.o: ${SP}hash.c ${SP}counter.c
	${CC} -c ${SP}hash.c -o ${BLD}hash.o ${CFLAGS} 


clean :
	rm ${BLD}*
	rm ${OUT}

run : ${OBJ}
	${CC} -o ${OUT} ${OBJ} ${CFLAGS} ${LDFLAGS}
	./${OUT} 

rebuild :
	make clean
	make run