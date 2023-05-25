BLD=bin/
CC=gcc	
CFLAGS=-Wall -ansi -pedantic -lreadline
OBJ=${BLD}main.o pile/pile.o calculator/calculator.o
LDFLAGS= -lm -lMLV
OUT=exe

all: ${OBJ}
	${CC} -o ${OUT} ${OBJ} ${CFLAGS} ${LDFLAGS} 

${BLD}main.o: main.c calculator/calculator.h
	${CC} -c main.c -o ${BLD}main.o ${CFLAGS} 

calculator/pile.o: pile/pile.c pile/pile.h
	${CC} -c pile/pile.c -o calculator/pile.o ${CFLAGS}

calculator/calculator.o: calculator/calculator.c calculator/calculator.h pile/pile.h
	${CC} -c calculator/calculator.c -o calculator/calculator.o ${CFLAGS}


clean :
	rm ${BLD}*
	rm ${OUT}

run : all
	./${OUT}
	
rebuild :
	make clean
	make run