/*
	Programmation C (TP9) - Exercice 1
	Max Ducoudré - INFO1
*/
#ifndef EXO1_H
#define EXO1_H

/*Fonction permettant de créer, afficher et libérer un malloc*/
void run_exo1(size_t alloc_size);

/*Permet d'allouer l'espace mémoire un pour un tableau d'integers */
int* allocate_malloc_int(size_t malloc_size);

/*Permet de remplir un malloc avec des entiers croissants */
void fill_malloc_int(int* malloc, size_t malloc_size);

/*Fonction pour afficher un malloc*/
void print_malloc_int(int* malloc, size_t malloc_size);

/*Fonction pour libérer l'espace mémoir alloué par le malloc*/
void free_malloc_int(int* malloc);

#endif