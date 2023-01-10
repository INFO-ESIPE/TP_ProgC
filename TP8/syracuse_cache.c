/*
	Permet de gérer le cache pour syracuse (TP8)
	Max Ducoudré - INFO1
*/
#include <stdio.h>
#include <stdlib.h>

#include "syracuse_cache.h"

void test_cache()
{
    unsigned long int *cache = init_cache();
    unsigned long int search;

    search = fly_lenght_recursive(27, cache);
    printf("result for [27] : %lu\n", search);

    search = fly_lenght_recursive(27, cache);
    printf("result for [27] : %lu\n", search);

    search = fly_lenght_recursive(28, cache);
    printf("result for [28] : %lu\n", search);

    search = fly_lenght_recursive(26, cache);
    printf("result for [26] : %lu\n", search);

    search = fly_lenght_recursive(50, cache);
    printf("result for [50] : %lu\n", search);

    search = fly_lenght_recursive(1000, cache);
    printf("result for [1000] : %lu\n", search);

    search = fly_lenght_recursive(199999999, cache);
    printf("result for [199999999] : %lu\n", search);

    printf("Free cache for memory\n");
    free(cache);
}


unsigned long int* init_cache()
{
    unsigned long int* cache = calloc(CACHE_SIZE, sizeof(unsigned long int));
    printf("Cache initialisation\n");

    return cache;
}

