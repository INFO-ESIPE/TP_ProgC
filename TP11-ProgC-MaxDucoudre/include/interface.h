#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void create_window();
void draw_game(Game game, MLV_Image *image, MLV_Font *font);
void draw_win_screen(Game game, MLV_Font *font);
void free_window();


int cell_width(Game game, MLV_Image *image);
int cell_height(Game game, MLV_Image *image);
void listen_mouse_click(Game *game, MLV_Image *image);
