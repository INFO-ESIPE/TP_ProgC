#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "../include/taquin.h"

Game *create_game(int width, int height) {
    int i,j;
    Game *game = malloc(sizeof(Game));
    game->width = width;
    game->height = height;
    game->cells = malloc(width * sizeof(Cell*));
    for (i = 0; i < width; i++) {
        game->cells[i] = malloc(height * sizeof(Cell));
        for (j = 0; j < height; j++) {
            game->cells[i][j].lig = i;
            game->cells[i][j].col = j;
        }
    }
    /* Black cell to move cells in*/
    game->cells[width-1][height-1].lig = -1;
    game->cells[width-1][height-1].col = -1;

    shuffle_game(game);

    game->moves = 0;
    game->start = time(NULL);

    return game;
}

void free_game(Game *game) {
    int i;
    for (i = 0; i < game->width; i++) {
        free(game->cells[i]);
    }
    free(game->cells);
    free(game);
}

void print_game(Game game) {
    int i, j;
    for (i = 0; i < game.width; i++) {
        for (j = 0; j < game.height; j++) {
            printf("| %d %d |", game.cells[i][j].lig, game.cells[i][j].col);
        }
        printf("\n");
    }
}

void swap_cells(Cell *cell1, Cell *cell2) {
    Cell tmp = *cell1;
    *cell1 = *cell2;
    *cell2 = tmp;
}

int move_cell(Game *game, Cell *cell) {
    int i, j;
    int success = 0;

    /* If click on black case */
    if (cell->lig == -1 && cell->col == -1) {
        return success;
    }

    for(j = 0; j < game->width; j++) {
        for(i = 0; i < game->height; i++) {
            if(&game->cells[i][j] == cell) {
                if(i > 0 && game->cells[i-1][j].lig == -1 && game->cells[i-1][j].col == -1) {
                    swap_cells(cell, &game->cells[i-1][j]);
                    success = 1;
                } else if (i < game->width-1 && game->cells[i+1][j].lig == -1 && game->cells[i+1][j].col == -1) {
                    swap_cells(cell, &game->cells[i+1][j]);
                    success = 1;
                } else if (j > 0 && game->cells[i][j-1].lig == -1 && game->cells[i][j-1].col == -1) {
                    swap_cells(cell, &game->cells[i][j-1]);
                    success = 1;
                } else if (j < game->height-1 && game->cells[i][j+1].lig == -1 && game->cells[i][j+1].col == -1) {
                    swap_cells(cell, &game->cells[i][j+1]);
                    success = 1;
                }

            }
        }
    }

    if(success)  game->moves++;
    

    return success;
}

void shuffle_game(Game *game) {
    int i, j, k;
    for (k = 0; k < 1000; k++) {
        i = rand() % game->width;
        j = rand() % game->height;
        move_cell(game, &game->cells[i][j]);
    }
}

int is_game_win(Game game) {

    int i, j;
    for (i = 0; i < game.width; i++) {
        for (j = 0; j < game.height; j++) {
            if(i == game.width-1 && j == game.height-1) continue;
            if (game.cells[i][j].lig != i || game.cells[i][j].col != j ) {
                return 0;
            }
        }
    }

    return 1;
}

void restart_game(Game *game) {
    shuffle_game(game);
    game->moves = 0;
    game->start = time(NULL);
}

void resolve_game(Game *game) {
    /*printf("Resolving game...\n");*/

}

