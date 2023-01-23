/*
	Permet de gérer le cache pour syracuse (TP8)
	Max Ducoudré - INFO1
*/
#include <stdio.h>
#include <stdlib.h>

#include "syracuse_cache.h"

void test_cache()
{
    int *cache = init_cache();

    unsigned long int max_index = 0;
    int max = 0;

    int value = 0;
    unsigned long int n;

    for(n = 1; n < CACHE_SIZE; n++)
    {
        /*printf("syracuse(%ld)\n", n);*/
        value = syracuse_rec(n, cache);
        if(max < value)
        {
            max = value;
            n = max_index;
        }
    }
    printf("La longueur de vol maximale est %d pour la valeur %ld.\n", max, max_index);


    printf("Free cache for memory\n");
    free(cache);
}


int* init_cache()
{

    int* cache = calloc(CACHE_SIZE, sizeof(int));
    printf("Cache initialisation\n");

    return cache;
}

