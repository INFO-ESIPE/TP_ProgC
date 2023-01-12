/*
	Programmation C (TP9) - Exercice 2
	Max Ducoudré - INFO1
*/
#ifndef EXO2_H
#define EXO2_H

/*Fonction permettant de créer, afficher et libérer un tableau en 2D de chars*/
void run_exo2(size_t size_d1, size_t size_d2);

/*Permet d'allouer l'espace mémoire un double tableau de char */
char** allocate_malloc_char2(size_t size_d1, size_t size_d2);

/*Permet de remplir un malloc avec des caractère */
void fill_malloc_char2(char** malloc, size_t size_d1, size_t size_d2);

/*Fonction pour afficher un malloc 2D de chars*/
void print_malloc_char2(char** malloc, size_t size_d1, size_t size_d2);

/*Fonction pour libérer l'espace mémoire alloué par le malloc de char en 2D*/
void free_malloc_char2(char** malloc, size_t size_d1);

#endif