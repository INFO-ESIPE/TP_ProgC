#ifndef INTERFACE_H
#define INTERFACE_H

#define WIDTH 900
#define HEIGHT 600
#define MARGIN 5

#define CASE_SIZE HEIGHT/BOARD_SIZE 

void create_window();
void draw_board(Board *board, Pile* pile, MLV_Image *dame);
void listen_action(Board *board, Pile *pile);
int coords_to_position(int x, int y);
#endif