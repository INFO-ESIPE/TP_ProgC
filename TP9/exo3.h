/*
	Programmation C (TP9) - Exercice 3
	Max Ducoudré - INFO1
*/
#ifndef EXO3_H
#define EXO3_H

/*Fonction permettant de lancer l'exercice 3*/
void run_exo3(int argc, char* argv[]);

/*Permet de remplir le malloc avec les caractères stockés dans argv*/
char** clone_argv(size_t argc, char* argv[]);

/*Permet d'afficher le contenu du malloc contenant des chaînes de caractères*/
void print_argv(char** arguments, size_t argc);


/*Permet de libérer l'espace mémoire alloué*/
void free_argv(char** arguments, size_t argc);

#endif