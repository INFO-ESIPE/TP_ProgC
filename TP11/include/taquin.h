/*
	Programmation C - TP11
	Max Ducoudré - INFO1
*/
#ifndef TAQUIN_H
#define TAQUIN_H
#include <MLV/MLV_all.h>

#define CASE_SPEED 10

/* ENUM */
typedef enum {
	RESIZE_IMAGE,
	KEEP_IMAGE_SIZE
} TaquinSize;



#define NONE 0
#define SOUTH 1
#define NORTH 2
#define EAST 3
#define WEST 4

typedef struct {
	int x;
	int y;
	int dest_x;
	int dest_y;
	int is_black_cell;
	int origin_column;
	int origin_line;
	MLV_Image* image;
} Cell;

typedef struct {
	int x;
	int y;
	int width;
	int height;
	int difficulty;
	int nb_column;
	int nb_line;
	int can_play; /* For movement animation */
	int is_randomizing;
	int swap_done;
	int swap_speed;
	int is_ended;
	PlayerData player_data;
	MLV_Image* image;
	Cell** cells;
} Taquin;

int getCellWidth(Taquin taquin);
int getCellHeight(Taquin taquin);
Taquin loadTaquin(MLV_Image* image, int nb_line, int nb_column, int difficulty, int level_num);
void freeTaquin(Taquin* taquin);
void drawTaquin(Taquin taquin);
void updateTaquin(Taquin* taquin, int* current_screen);
int isTaquinEnded(Taquin taquin);
int moveCell(Taquin* taquin, Cell* cell);
Cell* listenCellClick(Taquin *taquin);
void randomizeGrid(Taquin* taquin, int* swap_done);
Cell* getBlackCell(Taquin* taquin);


#endif
