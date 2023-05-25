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

int minus(int a, int b) {
    return a-b;
}

int modulo(int a, int b) {
    return a%b;
}

int expo(int a, int b) {
    if(a == 0) return 1;
    return expo(a, b-1)*a;
}

int factoriel(int a) {
    if(a == 1) return 1;
    return factoriel(a-1)*a;
}

BinOperation* register_calculator() {
    BinOperation* calculator = malloc(sizeof(BinOperation)*128);
    calculator['+'] = plus;
    calculator['*'] = times;
    calculator['/'] = divide;
    calculator['-'] = minus;
    calculator['%'] = modulo;
    calculator['%'] = modulo;
    calculator['^'] = expo;
    /*calculator['!'] = factoriel;*/
    return calculator;
}



