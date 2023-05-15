typedef struct node {
    char* word;
    struct node* next;
} Node, *List;

List* read_file(char* filename);
Node* allocate_word(char* word);
void insert_word(List *list, char* word);
int count_words(List *list);
void free_words(List *list);
Node* get_word(List *list, char* word);
