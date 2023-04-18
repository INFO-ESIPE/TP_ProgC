#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>

#include "../include/taquin.h"
#include "../include/interface.h"


int main(int argc, char *argv[])
{
    int end = 0;

    /* Init game */
    Game *game = create_game(3, 3);
    /*print_game(*game);*/
    
    /* Init graphics */
    create_window();
    MLV_Image *image = MLV_load_image("resources/image.png");
    MLV_resize_image(image, WINDOW_WIDTH, WINDOW_HEIGHT);
    MLV_Font *font = MLV_load_font("resources/Retro.ttf", 30);


    while (!end) {
        MLV_clear_window(MLV_COLOR_BLACK);
        draw_game(*game, image, font);

        if(is_game_win(*game)) {
            draw_win_screen(*game, font);
            if(MLV_get_keyboard_state(MLV_KEYBOARD_SPACE) == MLV_PRESSED) restart_game(game);
        } else {
            if(MLV_get_keyboard_state(MLV_KEYBOARD_SPACE) == MLV_PRESSED) resolve_game(game);
            listen_mouse_click(game, image);
        }

        if(MLV_get_keyboard_state(MLV_KEYBOARD_ESCAPE) == MLV_PRESSED) end = 1;


        MLV_actualise_window();
        MLV_wait_milliseconds(12);

    }

    /* Free memory */
    free_game(game);
    MLV_free_image(image);
    free_window();

    return EXIT_SUCCESS;
}