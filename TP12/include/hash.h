#define NB_PACK 4096
int hash(char *word);
List** create_hash();
void free_hash(List** hash_list);
void fill_hash(List** hash_list, char* filename);
void insert_word_hash(List** hash_list, char* word);
int count_words_hash(List** hash_list);