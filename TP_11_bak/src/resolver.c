typedef struct {
    int direction;
    Resolver* next;
} Resolver;


void push(Resolver** resolver, int direction) {
    Resolver* new_resolver = malloc(sizeof(Resolver));
    new_resolver->direction = direction;
    new_resolver->next = *resolver;
    *resolver = new_resolver;
}

int pop(Resolver** resolver) {
    int direction;
    Resolver* next_resolver;

    if(*resolver == NULL) {
        return -1;
    }

    direction = (*resolver)->direction;
    next_resolver = (*resolver)->next;
    free(*resolver);
    *resolver = next_resolver;

    return direction;
}