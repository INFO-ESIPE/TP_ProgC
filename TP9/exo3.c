/*
	Programmation C (TP9) - Exercice 3
	Max Ducoudré - INFO1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exo3.h"

void run_exo3(int argc, char* argv[]) {
    char** arguments = clone_argv(argc, argv);

    printf("--Exercice 3-- \nMalloc array of %d strings : \n", argc);
    print_argv(arguments, argc);

    free_argv(arguments, argc);
}

char** clone_argv(size_t argc, char* argv[]) {
    int i;
    char** new_argv = malloc(sizeof(char*) * argc);

    for(i = 0; i < argc; i++) {
        new_argv[i] = malloc(sizeof(char) * (strlen(argv[i]) + 1));
        strcpy(new_argv[i], argv[i]);
    }

    return new_argv;
}

void print_argv(char** arguments, size_t argc) {
    int i;
    for(i = 0; i < argc; i++) {
        printf("argv[%d] : %s\n", i, arguments[i]);
    }
}

void free_argv(char** arguments, size_t argc) {
    int i;
    for(i = 0; i < argc; i++) {
        free(arguments[i]);
    }
    free(arguments);
}