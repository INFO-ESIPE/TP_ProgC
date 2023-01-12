/*
	Programme Allocation de mémoire (TP9)
	Max Ducoudré - INFO1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exo1.h"
#include "exo2.h"
#include "exo3.h"

void usage();

int main(int argc, char* argv[])
{
    if(argc == 3 && strcmp(argv[1], "--exo1") == 0){
        run_exo1(atoi(argv[2]));
        return EXIT_SUCCESS;
    }
    else if(argc == 4 && strcmp(argv[1], "--exo2") == 0){
        run_exo2(atoi(argv[2]), atoi(argv[3]));
        return EXIT_SUCCESS;
    }
    else if(argc >= 2 && strcmp(argv[1], "--exo3") == 0){
        run_exo3(argc, argv);
        return EXIT_SUCCESS;
    }

    usage();
    return EXIT_FAILURE;
}



void usage() {
	printf("Usage: ./allocation [options]\n");
	printf("  --exo1 ALLOC_SIZE                        Run tests for exercice 1.\n");
	printf("  --exo2 ALLOC_SIZE_D1 ALLOC_SIZE_D2       Run tests for exercice 2.\n");
	printf("  --exo3 [arguments]                       Run tests for exercice 3.\n");
	printf("\n");
}
