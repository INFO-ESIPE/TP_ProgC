/*
	Programme permutation (TP6/EX2)
	Max Ducoudré - INFO1
*/

#include <stdio.h>
#include <stdlib.h>

/* nombre des entiers naturels à afficher les permutations*/
#define N 3

/*Signature des fonctions */
void permutations(int* array, int current, int max);
void printArray(int* array);

/*Pour l'affichage à la console*/
int recursive_depth = 0;

int main(int argc, char* argv[])
{
	int* array = calloc(N, sizeof(int)); /*Alloue la mémoire nécéssaire et met à °*/
	permutations(array, 0, N+1);
	free(array);

	return 1;
}

/*Fonction affichant toutes les permutations avec le tableau array (initié à 0)*/
void permutations(int* array, int current, int max)
{
	int i;

	/*Fin de la fonction quand current est plus grand que la taille du tableau*/
	if(current > max) return;

	/*Affichage à la console*/
	for(i = 0; i < recursive_depth; i++) printf("   ");
	printArray(array);
	recursive_depth++;


	for(i = 0; i < N; i++)
	{
		if(array[i] == 0)
		{
			array[i] = current;
			permutations(array, current+1, max);
			array[i] = 0;
			recursive_depth--;
		}
	}
}

/*Fonction affichant le tableau de taille N*/
void printArray(int* array)
{
	int i;
	printf("--> [");
	for(i = 0; i < N; i++)
	{
		printf("%d", array[i]);
		if(i != N-1) printf(",");
	}
	printf("]\n");
}