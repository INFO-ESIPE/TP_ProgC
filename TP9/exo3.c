/*
	Programmation C (TP9) - Exercice 3
	Max Ducoudré - INFO1
*/
#include <stdio.h>
#include <stdlib.h>
#include "exo3.h"

void run_exo3(int argc, char* argv[])
{
    char** arguments = allocate_empty_strings(argc, argv);
    fill_strings(arguments, argc, argv);
    printf("--Exercice 3-- \nMalloc array of %d strings : \n", argc);
    print_strings(arguments, argc);
    free_strings(arguments, argc);
}

char** allocate_empty_strings(size_t argc, char* argv[])
{
    int i,j;
    char** arguments_array = malloc(sizeof(char*)*argc);
    for(i = 0; i < argc; i++)
    {
        for(j = 0; argv[i][j] != '\0'; j++) {}
        arguments_array[i] = malloc(sizeof(char)*j);
    }
    return arguments_array;
}

void fill_strings(char** malloc_array, size_t argc, char* argv[])
{
    int i,j;
    for(i = 0; i < argc; i++)
        for(j = 0; argv[i][j] != '\0'; j++) malloc_array[i][j] = argv[i][j];
}

void print_strings(char** malloc_array, size_t argc)
{
    int i;
    for(i = 0; i < argc; i++)
        printf("argv[%d] : %s\n", i, malloc_array[i]);
}

void free_strings(char** malloc_array, size_t argc)
{
    int i;
    for(i = 0; i < argc; i++) free(malloc_array[i]);
    free(malloc_array);
}