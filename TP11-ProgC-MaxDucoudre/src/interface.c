#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <MLV/MLV_all.h>

#include "../include/taquin.h"
#include "../include/interface.h"

void create_window() {
    MLV_create_window("Taquin", "Taquin", WINDOW_WIDTH, WINDOW_HEIGHT);
}

void free_window() {
    MLV_free_window();
}

void draw_game(Game game, MLV_Image *image, MLV_Font *font) {

    /* Draw cells */
    int w = cell_width(game, image);
    int h = cell_height(game, image);

    int i, j;
    for (i = 0; i < game.width; i++) {
        for (j = 0; j < game.height; j++) {
            MLV_draw_partial_image(
                image,
                game.cells[i][j].lig * w,
                game.cells[i][j].col * h,
                w,
                h,
                i * w,
                j * h
            );
        }
    }

    /* Draw number of moves*/
    char moves[10];
    sprintf(moves, "Moves: %d", game.moves);
    MLV_draw_text_with_font(
        10,
        10,
        moves,
        font,
        MLV_COLOR_WHITE
    );

    /* Draw timer */
    int timer = time(NULL) - game.start;
    int minutes = timer / 60;
    int seconds = timer % 60;
    char time_str[10];
    sprintf(time_str, "%d:%d", minutes, seconds);
    MLV_draw_text_with_font(
        WINDOW_WIDTH - 80,
        10,
        time_str,
        font,
        MLV_COLOR_WHITE
    );

}

void draw_win_screen(Game game, MLV_Font *font) {
    MLV_draw_text_with_font(
        WINDOW_WIDTH / 2 - 100,
        WINDOW_HEIGHT / 2 - 40,
        "You win !",
        font,
        MLV_COLOR_WHITE
    );

    /* SPACE to restart under*/
    MLV_draw_text_with_font(
        WINDOW_WIDTH / 2 - 180,
        WINDOW_HEIGHT / 2 + 40,
        "'SPACE' to restart",
        font,
        MLV_COLOR_WHITE
    );
}

void listen_mouse_click(Game *game, MLV_Image *image) {
    int x, y;

    if(MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_RELEASED ) return; 

    MLV_get_mouse_position(&x, &y);

    int w = cell_width(*game, image);
    int h = cell_height(*game, image);
    int i = x / w;
    int j = y / h;

    move_cell(game, &game->cells[i][j]);
}

int cell_width(Game game, MLV_Image *image) {
    int img_width = MLV_get_image_width(image);
    
    return img_width / game.width;
}

int cell_height(Game game, MLV_Image *image) {
    int img_height = MLV_get_image_height(image);
    return img_height / game.height;
}