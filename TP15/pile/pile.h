#ifndef PILE_H
#define PILE_H

typedef struct {
    char** element;
    char* head;
    int size;
} Pile;

void push(Pile* pile, char* element);
char* pop(Pile* pile);
void print(Pile* pile);


#endif

