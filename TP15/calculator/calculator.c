#include "calculator.h"

int plus(int a, int b) {
    return a+b;
}
int times(int a, int b) {
    return a*b;
}
int divide(int a, int b) {
    return a/b;
}

BinOperation* register_calculator() {
    BinOperation* calculator = malloc(sizeof(BinOperation)*256);
    calculator['+'] = plus;
    calculator['*'] = times;
    calculator['/'] = divide;
    return calculator;
}



