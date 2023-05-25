#ifndef CALCULATOR_H
#define CALCULATOR_H


#include <stdlib.h>
#include "../pile/pile.h"

typedef int (*BinOperation)(int, int);


int plus(int a, int b);
int times(int a, int b);
int divide(int a, int b);

BinOperation* register_calculator();


#endif
