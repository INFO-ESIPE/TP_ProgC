/*
	Permet de faire des calculs sur la suite syracuse (TP8)
	Max Ducoudré - INFO1
*/
#ifndef SYRACUSE_H
#define SYRACUSE_H

#include "syracuse_cache.h"


/*Structure de données permettant de stocker les éléments d'une suite*/
struct SyracuseData {
    unsigned long int* result_array;
    unsigned long int fly_lenght;
    unsigned long int maximum_value;
};

/*Fonction permettant de vérifier si l'argument an est pair*/
int is_even(unsigned long int an);

/*Renvoie la valeur de suivante de an dans la suite de syracuse*/
unsigned long int next_element(unsigned long int an);


/*PARTIE 1*/
/*Permet de calculer la suite de syracuse de manière itérative puis renvois ses données*/
struct SyracuseData syracuse_iterative(unsigned long int an);

/*Permet de tester la fonction syracuse_iterative*/
void test_syracuse_iterative(unsigned long int an);

/*Permet d'afficher à la console les données de l'argument syracuse_data*/
void print_syracuse_data(struct SyracuseData syracuse_data);



/*PARTIE 2*/
/*Permet de récupérer le nombre d'étapes pour la valeur search_an dans la suite de syracuse récursivement
  Cette fonction met à jour le cache et l'utilise si possible*/
int fly_lenght_recursive(unsigned long int search_an, unsigned long int *cache);

/*Fonction pour calculer le nombre d'étapes de la suite de syracuse pour la valeur an itérativement*/
unsigned long int fly_lenght(unsigned long int an);


#endif

