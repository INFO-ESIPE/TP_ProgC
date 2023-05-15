#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/counter.h"
#include "../include/hash.h"

int hash(char *word) {
    int hash = 0;
    int i;
    for(i = 0; i < strlen(word); i++) {
        hash += (i + 1) * word[i]; 
    }
    hash = hash % NB_PACK;
    if(hash < 0) hash = -hash;

    return hash;
}

List** create_hash() {
    List** hash_list = malloc(NB_PACK * sizeof(List*));
    int i;
    for(i = 0; i < NB_PACK; i++) {
        hash_list[i] = malloc(sizeof(List));
    }
    return hash_list;
}

int count_words_hash(List** hash_list) {
    int i;
    int count = 0;
    for(i = 0; i < NB_PACK; i++) {
        count += count_words(hash_list[i]);
    }
    return count;
}


void free_hash(List** hash_list) {
    int i;
    for(i = 0; i < NB_PACK; i++) {
        free_words(hash_list[i]);
    }
    free(hash_list);
}

void insert_word_hash(List** hash_list, char* word) {
    int hash_value = hash(word);

    insert_word(hash_list[hash_value], word);
}

void fill_hash(List** hash_list, char* filename) {
    char word[200];
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
    }

    while(fscanf(file, "%s", word) != EOF) {
        insert_word_hash(hash_list, word);
    }
    fclose(file);
}