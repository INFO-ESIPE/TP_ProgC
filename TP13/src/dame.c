#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/dame.h"

int bit_value_ULI(Board n, int position) {    
    return n&(1UL << position) ? 1 : 0;
}

int set_positive_bit_ULI(Board* n, int position) {
    if(can_play(n, position)) {
        *n |= (1UL << position);
        return 1;
    } else return 0;
}

int can_play(Board* n, int position) {
    int line = position/BOARD_SIZE;
    int column = position%BOARD_SIZE;
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if (i == line || j == column || i+j == line+column || i-j == line-column){
                if(bit_value_ULI(*n, i*BOARD_SIZE+j)) {
                    return 0;  
                }
            }
        }
    }
    return 1;
}

int free_spaces(Board* n) {
    int i;
    int count = 0;
    for(i = 0; i < BOARD_SIZE*BOARD_SIZE; i++) {
        count += can_play(n, i);
    }
    return count;
}

int positive_bits(Board n) {
    int i;
    int count;
    for(i = 0; i < BOARD_SIZE*BOARD_SIZE; i++) {
        count += bit_value_ULI(n, i);
    }
    return count;
}

void set_negative_bit_ULI(Board* n, int position) {
    *n &= ~(1UL << position);
}
void print_ULI(Board n) {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++)
            printf("%d ",bit_value_ULI(n, i*BOARD_SIZE+j));
        printf("\n");
    }
}

Pile* init_pile() {
    Pile *pile = malloc(sizeof(Pile));
    int i;
    for(i = 0; i < BOARD_SIZE; i++) *pile[i] = -1;
    return pile;
}

void push(Pile *pile, int element) {
    int i;
    for(i = 0; i < BOARD_SIZE; i++) {
        if(*pile[i] == -1) {
            *pile[i] = element;
            break;
        }
    }
}

int pop(Pile *pile) {
    int i;
    for(i = BOARD_SIZE-1; i >= 0; i--) {
        if(*pile[i] != -1) {
            int element = *pile[i];
            *pile[i] = -1;
            return element;
        }
    }
    return -1;
}

int size(Pile *pile) {
    int i, size = 0;
    for(i = 0; i < BOARD_SIZE; i++) {
        if(*pile[i] != -1) size++;
        else break;
    }
    return size;
}