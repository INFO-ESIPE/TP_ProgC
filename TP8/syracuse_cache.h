/*
	Permet de faire des calculs sur la suite syracuse (TP8)
	Max Ducoudré - INFO1
*/

#ifndef SYRACUSE_CACHE_H
#define SYRACUSE_CACHE_H

#include "syracuse.h"

#define CACHE_SIZE 200000000

/*Fonction pour tester le cache*/
void test_cache();

/*Fonction pour réserver la mémoire du cache*/
int* init_cache();

#endif

