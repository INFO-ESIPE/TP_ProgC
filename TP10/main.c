/*
	Programmation C (TP10)
	Max Ducoudré - INFO1
*/
#include <stdio.h>
#include <stdlib.h>

#include "swap.h"
#include "name_list.h"


void test_exo1();
void test_exo2();

int main(int argc, char* argv[]) {

    /*test_exo1();*/

    test_exo2();

    return EXIT_SUCCESS;
}


void test_exo1() {
    /* Test mem swap EXO 1*/
    int int_1 = 1;
    int int_2 = 2;
    char* str_1 = "Hello";
    char* str_2 = "World";

    swap_mem(&str_1, &str_2, sizeof(str_1));
    printf("str_1 : %s | str_2 %s\n", str_1, str_2);

    swap_mem(&int_1, &int_2, sizeof(int));
    printf("int_1 : %d | int_2 %d\n", int_1, int_2);
}


void test_exo2() {
    FILE* file = fopen("liste_nom.txt", "r");
    char first[100];
    char last[100];
    int age;
    /*Cell* cell;*/
    List list;
    
    if(file == NULL) {
        printf("Erreur d'ouverture de fichier\n");
        return;
    }

    /* Normal insertion*/
    /*cell = malloc(sizeof(Cell*));
    list = cell;
    while(fscanf(file, "%s %s %d", first, last, &age) == 3) {
        cell->next = allocate_cell(first, last, age);
        cell = cell->next;
    }
    cell->next = NULL;
    print_list(list);
    free_list(list);
    fclose(file);*/


    /* Age ordered insertion*/
    file = fopen("liste_nom.txt", "r");
    list = NULL;
    while(fscanf(file, "%s %s %d", first, last, &age) == 3) {
        ordered_insertion(&list, allocate_cell(first, last, age), age_order);
    }
    print_list(list);
    free_list(list);


    /*fclose(file);*/

    

}