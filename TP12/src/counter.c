#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/counter.h"


Node* allocate_word(char* word)
{
    Node* node = malloc(sizeof(Node));
    node->word = malloc(strlen(word) + 1);
    strcpy(node->word, word);
    node->next = NULL;
    return node;
}


void insert_word(List *list, char* word) {
    Node* node;
    if(get_word(list, word) != NULL) return;
    node = allocate_word(word);
    if(list != NULL && *list == NULL) {
        *list = node;
    } else {
        node->next = *list;
        *list = node;
    }
}

void print_list(List *list) {
    Node* node;
    if(list == NULL) return;

    for (node = *list; node != NULL; node = node->next) {
        printf(" %s " , node->word);
    }
}

void free_words(List *list)
{
    Node* node;
    Node* next;
    
    if(list == NULL) return;

    for (node = *list; node != NULL; node = next) {
        next = node->next;
        free(node->word);
        free(node);
    }
    free(list);
}

int count_words(List *list) {
    Node* node;
    int count = 0;
    if(list == NULL) return 0;

    for (node = *list; node != NULL; node = node->next) {
        count++;
    }
    return count;
}

Node* get_word(List *list, char* word) {
    Node* node;
    if(list == NULL) return NULL;

    for (node = *list; node != NULL; node = node->next) {
        if(strcmp(node->word, word) == 0) {
            return node;
        }
    }
    return NULL;
}

List* read_file(char* filename)
{
    char word[200];
    List* list = malloc(sizeof(List));
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
    }

    while(fscanf(file, "%s", word) != EOF) {
        insert_word(list, word);
    }

    fclose(file);
    return list;
}

