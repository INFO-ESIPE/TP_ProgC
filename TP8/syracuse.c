/*
	Permet de faire des calculs sur la suite syracuse (TP8)
	Max Ducoudré - INFO1
*/

#include <stdio.h>
#include <stdlib.h>

#include "syracuse.h"


int is_even(unsigned long int an)
{
    if(an%2 == 0) return 1;
    return 0;
}

unsigned long int next_element(unsigned long int an)
{
    if(is_even(an))
        return an/2;
    return (3*an) + 1;
}

unsigned long int fly_lenght(unsigned long int an)
{
    int fly_lenght;
    for(fly_lenght = 0; an != 1; an=next_element(an), fly_lenght++);
    return fly_lenght;
}


unsigned long int syracuse_rec(unsigned long int n, int* cache)
{
  int an;
  if (n == 1) {
    return 0;
  }
  else if (n <= CACHE_SIZE && cache[n] != 0)
  {
    return cache[n];
  }
  else
  {
    if (n % 2 == 0) {n = n / 2;}
    else {n = 3 * n + 1;}

    an = syracuse_rec(n, cache);
    
    if (n < CACHE_SIZE && cache[n] == 0) {
      cache[n] = an;
      /*printf("Mise à jour du cache[%ld] = %d\n", n, cache[n]);*/
    }
  }
    return an + 1;

}

struct SyracuseData syracuse_iterative(unsigned long int an)
{
    struct SyracuseData sd;
    sd.result_array = malloc(sizeof(unsigned long int)*fly_lenght(an));
    sd.result_array[0] = an;
    sd.maximum_value = an;
    sd.fly_lenght = 0;

    for(sd.fly_lenght = 1; an != 1; sd.fly_lenght++)
    {
        an = next_element(an);
        sd.result_array[sd.fly_lenght] = an;
        if(sd.result_array[sd.fly_lenght] > sd.maximum_value)
            sd.maximum_value = sd.result_array[sd.fly_lenght];
        
    }
    sd.fly_lenght--;
    return sd;
}

void print_syracuse_data(struct SyracuseData syracuse_data)
{
    int i;
    for(i = 0; i < syracuse_data.fly_lenght; i++)
        printf("%lu ", syracuse_data.result_array[i]);
    
    printf("1 \nMaximum value : %lu\n", syracuse_data.maximum_value);
    printf("Fly length : %lu\n", syracuse_data.fly_lenght);
}


void test_syracuse_iterative(unsigned long int an)
{
    struct SyracuseData syracuse_data;
    printf("syracuse_iterative(%lu) : \n", an);
    syracuse_data = syracuse_iterative(an);
    print_syracuse_data(syracuse_data);
    free(syracuse_data.result_array);

}