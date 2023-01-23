/*
	Programme Syracuse (TP8)
	Max Ducoudré - INFO1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "syracuse.h"
#include "syracuse_cache.h"


void usage();

int main(int argc, char* argv[])
{

    int n;

    if(argc == 3 && strcmp(argv[1], "--syracuse_iterative") == 0){
        n = atoi(argv[2]);
        test_syracuse_iterative(n);
        return EXIT_SUCCESS;

    } else if(argc == 2 && strcmp(argv[1], "--test_cache") == 0)
    {
        test_cache();
        return EXIT_SUCCESS;
    }

    usage();
    return EXIT_FAILURE;
}



void usage() {
	printf("Usage: ./syracuse [options]\n");
	printf("  --syracuse_iterative n           Print syracuse sequence for the value n (iterative).\n");
	printf("  --test_cache                     Test syracuse cache.\n");
	printf("\n");
}
