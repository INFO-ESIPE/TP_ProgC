#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include "../include/dame.h"
#include "../include/interface.h"


int main(int argc, char *argv[])
{
    Board board = 0;
    Pile* pile = init_pile();
    MLV_Image* dame;
    
    create_window();
    dame = MLV_load_image("dame.png");
    while(!MLV_get_keyboard_state(MLV_KEYBOARD_ESCAPE) == MLV_PRESSED) {
        draw_board(&board, pile, dame);
        listen_action(&board, pile);
    }

    free(pile);
    MLV_free_image(dame);
    MLV_free_window();

    print_ULI(board);
    return EXIT_SUCCESS;
}