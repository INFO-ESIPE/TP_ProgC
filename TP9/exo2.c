/*
	Programmation C (TP9) - Exercice 2
	Max Ducoudré - INFO1
*/
#include <stdio.h>
#include <stdlib.h>
#include "exo2.h"

/*Fonction permettant de créer, afficher et libérer un tableau en 2D de chars*/
void run_exo2(size_t size_d1, size_t size_d2)
{
    char** malloc_array = allocate_malloc_char2(size_d1, size_d2); /*On alloue la mémoire*/
    fill_malloc_char2(malloc_array, size_d1, size_d2); /*On rempli le tableau*/
    printf("--Exercice 2-- \nMalloc array of %ldx%ld chars : \n", size_d1, size_d2);
    print_malloc_char2(malloc_array, size_d1, size_d2);
    free_malloc_char2(malloc_array, size_d1); /*Puis on libère la mémoire*/
}

/*Permet d'allouer l'espace mémoire un double tableau de char */
char** allocate_malloc_char2(size_t size_d1, size_t size_d2)
{
    int i;
    char** malloc_array = malloc(sizeof(char*)*size_d1);
    for(i = 0; i < size_d1; i++) malloc_array[i] = malloc(sizeof(char)*size_d2);

    return malloc_array;
}

/*Permet de remplir un malloc avec des caractère */
void fill_malloc_char2(char** malloc_array, size_t size_d1, size_t size_d2)
{
    int i,j;
    for(i = 0; i < size_d1; i++){
        for(j = 0; j < size_d2; j++) {
            malloc_array[i][j] = 'a'+i+j;
        }
    }
}

/*Fonction pour afficher un malloc 2D de chars*/
void print_malloc_char2(char** malloc_array, size_t size_d1, size_t size_d2)
{
    int i,j;
    for(i = 0; i < size_d1; i++){
        for(j = 0; j < size_d2; j++) {
            printf(" %c ", malloc_array[i][j]);
        }
        printf("\n");
    }
}

/*Fonction pour libérer l'espace mémoire alloué par le malloc de char en 2D*/
void free_malloc_char2(char** malloc_array, size_t size_d1)
{
    int i;
    for(i = 0; i < size_d1; i++) free(malloc_array[i]);
    free(malloc_array);
}