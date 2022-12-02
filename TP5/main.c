#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ARRAYS_EQUALS 1   
#define ARRAYS_NOT_EQUALS 0   


/* Allocate memory for an array which can contain `size`
   integers. The returned C array has memory for an extra last
   integer labelling the end of the array. */
int* allocate_integer_array(int size){
  int* new_tab;

  new_tab = (int*)malloc((size+1)*sizeof(int));
  if (new_tab == NULL){
    fprintf(stderr, "Memory allocation error\n");
    return NULL;
  }
  new_tab[size] = -1;
  return new_tab;
}


/* Free an integer array */
void free_integer_array(int* tab){
  free(tab);
}


/* Retourne la longueur d’un
   tableau d’entier */
int array_size(int* array)
{
	int compteur = 0;
	while(array[compteur] != -1)
	{
		compteur++;
	}

	return compteur;
}

/*
affiche le contenu d’un
tableau sur la sortie standard
*/
void print_array(int* array)
{
	int compteur = 0;
	printf("| ");

	while(array[compteur] != -1)
	{
		printf("%d | ", array[compteur]);
		compteur++;
	}

	printf("\n");
}


/* Fill the array with random values between arguments min and max*/
void fill_array_with_random_values(int* array, int min, int max)
{
	int i;
	int n = array_size(array);


	for(i = 0; i<n; i++ ) 
		array[i] = (rand() % (max - min)) + min;
	
}

/*Retourne une nouvelle copie
identique du tableau donné en argument
*/
int* copy_array(int* array)
{
	int arraySize = array_size(array);
	int* copiedArray = allocate_integer_array(arraySize);
	int i;

	for(i = 0; i<arraySize; i++)
		copiedArray[i] = array[i];

	return copiedArray;
}

/*  retourne 1 si les deux tableaux ont le même contenu et 0 sinon */
int are_arrays_equal(int* first, int* second) 
{
	int i;
	int firstSize = array_size(first);

	if(firstSize != array_size(second))
		return ARRAYS_NOT_EQUALS;

	for(i = 0; i < firstSize; i++)
		if(first[i] != second[i])
			return ARRAYS_NOT_EQUALS;


	return ARRAYS_EQUALS;

}

/*
Demande à l’utilisateur d’entrer en console une longueur puis des entiers positifs. 
Retourne ensuite un tableau fraîchement alloué contenant les entiers donnés par l’utilisateur
*/
int* fill_array()
{
	int i;
	int arraySize;
	int* array;

	printf("Entrez la taille de votre tableau : ");
	if(scanf("%d", &arraySize) != 1)
	{
		fprintf(stderr, "Error reading array size\n");
		exit(1);
	}


	array = allocate_integer_array(arraySize);

	printf("Entrez %d entiers positifs : ", arraySize);
	for(i = 0; i < arraySize; i++)
		if(scanf("%d", &array[i]) != 1)
		{
		    fprintf(stderr, "Error reading array elements\n");
			exit(1);
		}


	return array;

}

/* Retourne un nouveau tableau contenant size entiers positifs compris entre 0 et max_entry*/
int* random_array(int size, int max_entry)
{
	int* array = allocate_integer_array(size);
	int i;

	for(i = 0; i<size; i++ ) 
	{
		array[i] = (rand() % max_entry);
	}


	return array;
}


/* Prend en argument deux tableaux et retourne un nouveau tableau contenant les entrées concaténées des deux tableaux. */
int* concat_array(int* first, int* second) 
{
	int firstSize = array_size(first);
	int secondSize = array_size(second);
	int totalSize = firstSize + secondSize;

	int* array = allocate_integer_array(totalSize);

	int i;	

	for(i = 0; i < firstSize; i++)
		array[i] = first[i];

	for(i = 0; i < secondSize; i++)
		array[firstSize+i] = second[i];

	return array;
}

int* merge_sorted_arrays(int* first, int* second)
{
	int firstSize = array_size(first);
	int secondSize = array_size(second);
	int totalSize = firstSize + secondSize;
	int i;
	int compteur_first = 0;
	int compteur_second = 0;
	int* array = allocate_integer_array(totalSize);


	printf("Merge the two following ones : \n");
	print_array(first);
	print_array(second);

	for(i = 0; i < totalSize; i++)
	{
		if(first[compteur_first] <= second[compteur_second] && first[compteur_first] != -1)
		{
			array[i] = first[compteur_first];
			compteur_first ++;
		}
		else
		{
			array[i] = second[compteur_second];
			compteur_second ++;
		}

	}
	print_array(array);

	return array;
}
/* 
Fonction qui prend en argument un tableau et deux pointeurs vers des tableaux. Cette fonction
doit fabriquer deux tableaux (qui seront placés dans les pointeurs) contenant chacun
la moitié des éléments du tableau array en argument.
*/
void split_arrays(int* array, int** first, int** second)
{


	int arraySize = array_size(array);
	int i = 0;
	int j;

	int sizeFirst = arraySize/2;
	int sizeSecond = arraySize-sizeFirst;
	*first = allocate_integer_array(sizeFirst);
	*second = allocate_integer_array(sizeSecond);



	for(j = 0; j < array_size(*first); j++, i++)
		(*first)[j] = array[i];

	for(j = 0; j < array_size(*second); j++, i++)
		(*second)[j] = array[i];


	printf("Split array in two part : \n");
	print_array(array);
	print_array(*first);
	print_array(*second);

}


/* Tri fusion */
int* merge_sort(int* array)
{
 	int* split1;
 	int* split2;
 	int* sorted_array;

 	if(array_size(array) == 1) return array;


 	split_arrays(array, &split1, &split2);

 	split1 = merge_sort(split1);

 	split2 = merge_sort(split2);

 	sorted_array = merge_sorted_arrays(split1, split2);

 	free(split1);
 	free(split2);

 	return sorted_array;
}

void test_functions_ex1()
{
	int* myArray;
	int* mySecondArray;
	int* array_with_different_size;
	int* array_with_different_values;

  printf("Fonctions test exercice 1 : \n");



 /* Création d'un tableau d'entier */
  printf("1 : myArray = allocate_integer_array(10)\n");
  myArray = allocate_integer_array(10); 
  fill_array_with_random_values(myArray, 0, 10); /* On rempli le tableau avec des valeurs */


  /* On affiche le contenu et la taille du tableau nouvellement créé*/
  printf("2 :array_size(myArray) = %d\n", array_size(myArray));
  printf("3 : print_array(myArray)\n");
  print_array(myArray);


  /* On copie le premier tableau puis on l'affiche pour vérifier qu'ils sont identiques */
  printf("4 : mySecondArray = copy_array(myArray)\n");
  mySecondArray = copy_array(myArray);
  printf("5 : print_array(mySecondArray)\n");
  print_array(mySecondArray);


  /* Test de l'égalité des tableaux*/
  printf("6 : are_arrays_equal(myArray, mySecondArray) = %d\n", are_arrays_equal(myArray, mySecondArray)); /* Avec des tableaux identiques */
  
  array_with_different_size = allocate_integer_array(6);
  printf("7 : are_arrays_equal(myArray, allocate_integer_array(6)) = %d\n", are_arrays_equal(myArray, array_with_different_size)); /* Avec des tableaux de taille différentes*/
  free(array_with_different_size);

  array_with_different_values = allocate_integer_array(10);
  printf("8 : are_arrays_equal(myArray, allocate_integer_array(10)) = %d\n", are_arrays_equal(myArray, array_with_different_values)); /* Avec des tableaux de même taille mais des valeurs différentes*/
  free(array_with_different_values);



  /* On libère la mémoire des tableaux*/
  printf("9 : free_integer_array(myArray)\n");
  free(myArray);
  printf("10 : free_integer_array(mySecondArray)\n");
  free(mySecondArray);

}

void test_functions_ex2()
{
  int* myArray;
  int* randomArray;
  int* concatArray;
  printf("Fonctions test exercice 2 : \n");


  /* Création d'un tableau par l'utilisateur*/
  myArray = fill_array();
  print_array(myArray);

  /* Création d'un tableau aléatoire */  
  randomArray = random_array(10, 100);
  print_array(randomArray);


  /* On concatène ces deux tableaux*/
  concatArray = concat_array(myArray, randomArray);
  print_array(concatArray);


  free(concatArray);
  free(myArray);
  free(randomArray);
  

}

void test_functions_ex3()
{

	/*int* randomArray = random_array(20,100);*/

	int* array_to_merge_sort = allocate_integer_array(15);
	int* array_merge_sorted;

	int* array_to_split = allocate_integer_array(9); 
	int* array_split_1;
	int* array_split_2; 


	int* firstArray = fill_array();
	int* secondArray = fill_array();
	int* merged_arrays;
	printf("Fonctions test exercice 3 :\n");

	
	printf("Merge sorted arrays : \n");
	print_array(firstArray);
	print_array(secondArray);
	merged_arrays = merge_sorted_arrays(firstArray,secondArray);
	print_array(merged_arrays);
	

	printf("Split array :\n");
	fill_array_with_random_values(array_to_split, 0, 10); /* On rempli le tableau avec des valeurs */
	print_array(array_to_split);
	split_arrays(array_to_split, &array_split_1, &array_split_2);
	print_array(array_split_1);
	print_array(array_split_2);
	

	printf("Merge sort :\n");
	fill_array_with_random_values(array_to_merge_sort, 0, 15); /* On rempli le tableau avec des valeurs */
	print_array(array_to_merge_sort);
	array_merge_sorted = merge_sort(array_to_merge_sort);
	printf("Merge sort array result : \n");
	print_array(array_merge_sorted);



	free(firstArray);
	free(secondArray);
	free(merged_arrays);
	free(array_split_1);
	free(array_split_2);
	free(array_merge_sorted);
	free(array_to_merge_sort);







}

/* An empty main to test the compilation of the allocation and free
   functions. */
int main(int argc, char* argv[]){
	srand(time(NULL));


	/* Permet de tester les fonctions de l'exercice 1*/
	/*test_functions_ex1();*/
 

	/* Permet de tester les fonctions de l'exercice 2*/
	/*test_functions_ex2();*/


	/* Permet de tester les fonctions de l'exercice 3*/
	test_functions_ex3();


  return 0;
}

