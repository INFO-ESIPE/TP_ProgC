#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "name_list.h"


Cell* allocate_cell(char* first, char* last, int age) {
    Cell* cell = malloc(sizeof(Cell));

    cell->first_name = malloc(strlen(first)+1);
    strcpy(cell->first_name, first);

    cell->last_name = malloc(strlen(last)+1);
    strcpy(cell->last_name, last);

    cell->age = age;

    return cell;
}
int age_order(Cell* p1, Cell* p2) {
    if(p1->age == p2->age)
        return 0;
    else if(p1->age > p2->age)
        return 1;
    else
        return -1;
}

int name_order(Cell* p1, Cell* p2) {
    int cmp = strcmp(p1->last_name, p2->last_name);
    if(cmp == 0) {
        cmp = strcmp(p1->first_name, p2->first_name);
    }
    return cmp;
}


void ordered_insertion(List* l, Cell* new, int order_func(Cell*, Cell*)) {
    Cell *cell = *l;
    Cell *prev = NULL;

    while(cell != NULL && order_func(cell, new) < 0) {
        prev = cell;
        cell = cell->next;
    }

    if(prev == NULL) {
        new->next = *l;
        *l = new;
    } else {
        new->next = prev->next;
        prev->next = new;
    }
}

void print_list(List l) {
    Cell* cell = l;

    printf("====List===\n");
    while(cell != NULL) {
        printf("CELL[%s %s %d]\n", cell->first_name, cell->last_name, cell->age);
        cell = cell->next;
    }
}

void free_list(List l) {
    Cell* cell = l;
    Cell* tmp;

    while(cell != NULL) {
        tmp = cell;
        cell = cell->next;
        free(tmp->first_name);
        free(tmp->last_name);
        free(tmp);
    }



}