/*
	Programmation C (TP9) - Exercice 3
	Max Ducoudré - INFO1
*/
#ifndef EXO3_H
#define EXO3_H

/*Fonction permettant de lancer l'exercice 3*/
void run_exo3(int argc, char* argv[]);

/*Fonction allouant l'espace mémoire nécéssaires pour stocker les arguments du programme*/
char** allocate_empty_strings(size_t argc, char* argv[]);

/*Permet de remplir le malloc avec les caractères stockés dans argv*/
void fill_strings(char** malloc_array, size_t argc, char* argv[]);

/*Permet d'afficher le contenu du malloc contenant des chaînes de caractères*/
void print_strings(char** malloc_array, size_t argc);

/*Permet de libérer l'espace mémoire alloué*/
void free_strings(char** malloc_array, size_t argc);


#endif