#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../include/counter.h"
#include "../include/hash.h"

int main(int argc, char *argv[])
{
    unsigned int start;
    /*List* list = NULL;*/
    List** hash_list = NULL;


    /* Test hash table */
    start = time(NULL);
    hash_list = create_hash();
    printf("Counting words in Germinal (HASH)...\n");
    fill_hash(hash_list, "germinal.txt");
    printf("%d different words found in Germinal (%ld seconds) !\n", count_words_hash(hash_list), time(NULL) - start);
    free_hash(hash_list);
    
    /* Test linked list */
    /*
    start = time(NULL);
    list = NULL;
    printf("Counting words in Germinal (LINKED LIST)...\n");
    list = read_file("germinal.txt");
    printf("%d different words found in Germinal (%ld seconds) !\n", count_words(list), time(NULL) - start);
    free_words(list);
    */

    return EXIT_SUCCESS;
}