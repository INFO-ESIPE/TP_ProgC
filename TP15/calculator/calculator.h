#ifndef CALCULATOR_H
#define CALCULATOR_H


#include <stdlib.h>

typedef int (*BinOperation)(int, int);
typedef int (*UnaryOperation)(int, int);

int plus(int a, int b);
int times(int a, int b);
int divide(int a, int b);
int minus(int a, int b);
int modulo(int a, int b);
int expo(int a, int b);
int factoriel(int a);

BinOperation* register_calculator();


#endif
