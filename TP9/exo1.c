/*
	Programmation C (TP9) - Exercice 1
	Max Ducoudré - INFO1
*/
#include <stdio.h>
#include <stdlib.h>
#include "exo1.h"



/*Fonction permettant de créer, afficher et libérer un malloc*/
void run_exo1(size_t malloc_size)
{
    int* malloc_array = allocate_malloc_int(malloc_size);
    fill_malloc_int(malloc_array, malloc_size);
    printf("--Exercice 1-- \nMalloc array of %ld integers : \n", malloc_size);
    print_malloc_int(malloc_array, malloc_size);
    free_malloc_int(malloc_array); 
}

/*Fonction pour libérer l'espace mémoire alloué par le malloc*/
void free_malloc_int(int* malloc)
{
    free(malloc);
}

/*Fonction pour afficher un malloc*/
void print_malloc_int(int* malloc, size_t malloc_size)
{
    int i;
    printf("[ ");
    for(i = 0; i <malloc_size; i++) printf(" %d ", malloc[i]);
    printf(" ]\n");
}

/*Permet de remplir un malloc avec des entiers croissants */
void fill_malloc_int(int* malloc, size_t malloc_size)
{
    int i;
    for(i = 0; i<malloc_size; i++)
        malloc[i] = i+1; /*On rempli le tableau d'entiers*/
}

/*Permet d'allouer l'espace mémoire un pour un tableau d'integers */
int* allocate_malloc_int(size_t int_number)
{
    return malloc(sizeof(int)*int_number);
}