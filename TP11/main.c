/*
	Programmation C - TP11
	Max Ducoudré - INFO1
    Main du Taquin
*/

#include <stdio.h>
#include <stdlib.h>

/* Bibliothèque pour gérer l'aléatoire*/
#include <time.h>

/* Constantes nécéssaire au programme */
#include "headers/constants.h"
#include "headers/taquin.h"

/* Permet de récupérer les signaux*/
#include <signal.h>
#include <unistd.h>


void freeMemory();
void printUsage(char* exName);

/* Fonction main du programme*/
int main(int argc, char* argv[])
{
    int game_preparation_success;

	srand(time(NULL)); 
    signal(SIGINT, freeMemory); 

    game_preparation_success = prepareTaquin(
        4, 
        4, 
        650, 
        650, 
        "resources/images/image_1.png", 
        1);

    if(!game_preparation_success)
    {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void printUsage(char* exName)
{
    printf("Usage & options:\n");
    printf("%s                       Start taquin with a default image.\n",exName);
    exit(EXIT_FAILURE);
}


void freeMemory()
{

}