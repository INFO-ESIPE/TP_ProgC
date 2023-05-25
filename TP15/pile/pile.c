#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

static int tab[1000];
static int current = 0;

void push_stack(int element) {
    tab[current++] = element; 
}

int pop_stack() {
    return tab[--current];
}

int size_stack() {
    return current;
}

void empty_stack() {
    current = 0;
}

void print_stack()  {
    int i;
    for(i = 0; i < current; i++) {
        printf("%d\n", tab[i]);
    }
}

void reverse_head_stack() {
    int tmp = tab[current-1];
    tab[current-1] = tab[current-2];
    tab[current-2] = tmp;
}

int head_stack() {
    return tab[current-1];
}