#include <MLV/MLV_all.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/data.h"
#include "../include/taquin.h"
#include "../include/constants.h"
#include "../include/menu.h"

LevelSettings* initLevelSettings() {
    LevelSettings* levelSettings = malloc(sizeof(LevelSettings) * 3);
    int i = 0;
    levelSettings[i].num_level = 1;
    levelSettings[i].nb_line = 5;
    levelSettings[i].nb_col = 5;
    levelSettings[i].image = MLV_load_image("resources/images/image_1.png");
    levelSettings[i].width = WIN_WIDTH/3 - MARGIN;
    levelSettings[i].height = WIN_WIDTH/3 - MARGIN;
    levelSettings[i].x = i * WIN_WIDTH/3 + MARGIN/2;
    levelSettings[i].y = MARGIN;
    levelSettings[i].is_over = 0;
    levelSettings[i].score_str = scoreToString(i+1);
    i++;

    levelSettings[i].num_level = 2;
    levelSettings[i].nb_line = 3;
    levelSettings[i].nb_col = 3;
    levelSettings[i].image = MLV_load_image("resources/images/image_2.png");
    levelSettings[i].width = WIN_WIDTH/3 - MARGIN;
    levelSettings[i].height = WIN_WIDTH/3 - MARGIN;
    levelSettings[i].x = i * WIN_WIDTH/3 + MARGIN/2;
    levelSettings[i].y = MARGIN;
    levelSettings[i].is_over = 0;
    levelSettings[i].score_str = scoreToString(i+1);
    i++;

    levelSettings[i].num_level = 3;
    levelSettings[i].nb_line = 10;
    levelSettings[i].nb_col = 10;
    levelSettings[i].image = MLV_load_image("resources/images/image_3.png");
    levelSettings[i].width = WIN_WIDTH/3 - MARGIN;
    levelSettings[i].height = WIN_WIDTH/3 - MARGIN;
    levelSettings[i].x = i * WIN_WIDTH/3 + MARGIN/2;
    levelSettings[i].y = MARGIN;
    levelSettings[i].is_over = 0;
    levelSettings[i].score_str = scoreToString(i+1);
    i++;


    return levelSettings;
}

void freeLevelSettings(LevelSettings* levelSettings, int nb_levels) {
    int i;
    for(i = 0; i < nb_levels; i++) {
        MLV_free_image(levelSettings[i].image);
        free(levelSettings[i].score_str);

    }
    free(levelSettings);
}

void listenMenuEvents(LevelSettings* levelSettings, int nb_levels, int* current_screen, Taquin *taquin) {
    int mouse_x, mouse_y;
    int i;
    MLV_get_mouse_position(&mouse_x, &mouse_y);

    /* Over */
    for(i = 0; i < nb_levels; i++) {
        if(mouse_x > levelSettings[i].x && mouse_x < levelSettings[i].x + levelSettings[i].width &&
            mouse_y > levelSettings[i].y && mouse_y < levelSettings[i].y + levelSettings[i].height) {
            levelSettings[i].is_over = 1;
        } else {
            levelSettings[i].is_over = 0;
        }
    }

    /*Click*/
    if(MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED ) {
        for(i = 0; i < nb_levels; i++) {
            if(levelSettings[i].is_over) {
                *current_screen = GAME_SCREEN;
                *taquin = loadTaquin(levelSettings[i].image, levelSettings[i].nb_line, levelSettings[i].nb_col, 300, levelSettings[i].num_level);
            }
        }
    }


}

void drawMenu(LevelSettings* levelSettings, int nb_levels) {
    int i;
    char text[100];
    MLV_Font* font = MLV_load_font("resources/Retro.ttf", 20);
    MLV_Image* image;
    for(i = 0; i < nb_levels; i++) {
        image = MLV_copy_image(levelSettings[i].image);
        MLV_resize_image(image, levelSettings[i].width, levelSettings[i].height);
        MLV_draw_image(image, levelSettings[i].x, levelSettings[i].y);

        sprintf(text, "Level %d (%dx%d)", levelSettings[i].num_level, levelSettings[i].nb_line, levelSettings[i].nb_col);
        MLV_draw_text_with_font(
            i * WIN_WIDTH/nb_levels + MARGIN/2,
            WIN_WIDTH/nb_levels + MARGIN/2,
            text,
            font,
            MLV_COLOR_WHITE
        );


        MLV_draw_text_box_with_font(
            levelSettings[i].x, 
            levelSettings[i].y + levelSettings[i].height + MARGIN*3,
            levelSettings[i].width,
            WIN_HEIGHT - MARGIN*2 - levelSettings[i].height,
            levelSettings[i].score_str,
            font,
            10,
            MLV_COLOR_BLACK,
            MLV_COLOR_WHITE,
            MLV_COLOR_PURPLE,
            MLV_TEXT_LEFT,
            MLV_HORIZONTAL_LEFT,
            MLV_VERTICAL_TOP
            );

        if(levelSettings[i].is_over) {
            MLV_draw_rectangle(
                levelSettings[i].x,
                levelSettings[i].y,
                levelSettings[i].width,
                levelSettings[i].height,
                MLV_COLOR_GREEN
            );
        }
    }
    
    MLV_free_font(font);
    MLV_free_image(image);
}