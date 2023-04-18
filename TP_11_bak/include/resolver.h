typedef struct {
    int direction;
    Resolver* next;
} Resolver;


void push(Resolver** resolver, int direction);

void pop(Resolver** resolver);
