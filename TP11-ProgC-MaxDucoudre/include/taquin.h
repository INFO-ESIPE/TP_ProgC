#define SOUTH 1
#define NORTH 2
#define EAST 3
#define WEST 4

typedef struct {
    int lig;
    int col;
} Cell;

typedef struct {
    int width;
    int height;
    Cell **cells;
    int moves;
    int start;
} Game;

Game *create_game(int width, int height);
void free_game(Game *game);
void print_game(Game game);
int move_cell(Game *game, Cell *cell);
void shuffle_game(Game *game);
int is_game_win(Game game);

void restart_game(Game *game);
void resolve_game(Game *game);