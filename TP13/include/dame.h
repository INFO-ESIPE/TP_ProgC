#ifndef DAME_H
#define DAME_H

typedef unsigned long int Board;
#define BOARD_SIZE sizeof(Board)
typedef int Pile[BOARD_SIZE]; 


Pile* init_pile();
void push(Pile *pile, int element);
int pop(Pile *pile);
int size(Pile *pile);

int bit_value_ULI(Board n, int position);
void print_ULI(Board n);
int set_positive_bit_ULI(Board* n, int position);
void set_negative_bit_ULI(Board* n, int position);
int can_play(Board* n, int position);
int free_spaces(Board* n);
int positive_bits(Board n);

#endif