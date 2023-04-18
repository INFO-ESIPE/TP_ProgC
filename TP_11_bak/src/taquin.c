#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "./../include/data.h"
#include "./../include/constants.h"
#include "./../include/taquin.h"

int getCellWidth(Taquin taquin) { 
	return taquin.width / taquin.nb_column;
}
int getCellHeight(Taquin taquin) { 
	return taquin.height / taquin.nb_line;
}
Taquin loadTaquin(MLV_Image* image, int nb_line, int nb_column, int difficulty, int level_num) {
	Taquin taquin;
	int i,j;

	taquin.player_data = initPlayerData(level_num);

	/* Init taquin position */
	taquin.x = MARGIN;
	taquin.y = MARGIN;
	taquin.nb_column = nb_column;
	taquin.nb_line = nb_line;
	taquin.can_play = 1;
	taquin.is_randomizing = 1;
	taquin.swap_done = 0;
	taquin.difficulty = difficulty;
	taquin.swap_speed = 10;
	taquin.is_ended = 0;
	

	/* Set taquin size */
	taquin.width = WIN_WIDTH - 2 * MARGIN;
	taquin.height = WIN_HEIGHT - 2 * MARGIN;

	/* Load taquin image*/
	taquin.image = image;
	MLV_resize_image(taquin.image, taquin.width, taquin.height);

	/* Init taquin cells */
	taquin.cells = malloc(sizeof(Cell) * nb_line);
	for(i = 0; i < nb_line; i++) {
		taquin.cells[i] = malloc(sizeof(Cell) * nb_column);
	}

	/* Init taquin cells data */
	for(i = 0; i < nb_line; i++) {
		for(j = 0; j < nb_column; j++) {
			taquin.cells[i][j].x = taquin.x + j * getCellWidth(taquin);
			taquin.cells[i][j].dest_x = taquin.cells[i][j].x;
			taquin.cells[i][j].y = taquin.y + i * getCellHeight(taquin);
			taquin.cells[i][j].dest_y = taquin.cells[i][j].y;
			taquin.cells[i][j].origin_line = i;
			taquin.cells[i][j].origin_column = j;
			taquin.cells[i][j].image = MLV_copy_partial_image(				
				taquin.image,
				j * getCellWidth(taquin),
				i * getCellHeight(taquin),
				getCellWidth(taquin),
				getCellHeight(taquin)
			);
			taquin.cells[i][j].is_black_cell = 0;
		}
	}
	taquin.cells[nb_line - 1][nb_column - 1].is_black_cell = 1;
	
	return taquin;
}

Cell* getBlackCell(Taquin* taquin) {
	int i, j;
	for(i = 0; i < taquin->nb_line; i++) {
		for(j = 0; j < taquin->nb_column; j++) {
			if(taquin->cells[i][j].is_black_cell == 1) {
				return &taquin->cells[i][j];
			}
		}
	}

	return NULL;
}

void randomizeGrid(Taquin* taquin, int* swap_done) {
	int i, j;
	int rand_direction = NONE;
	int is_rand_direction_valid = 1;

	if(!taquin->can_play) return;

	for(i = 0; i < taquin->nb_line; i++) {
		for(j = 0; j < taquin->nb_column; j++) {
			if(taquin->cells[i][j].is_black_cell == 1) {

				do {
					rand_direction = rand() % 4 + 1;
					is_rand_direction_valid = 1;

					if(rand_direction == NORTH) {
						if(i + 1 >= taquin->nb_line) {
							is_rand_direction_valid = 0;
						}
					} else if(rand_direction == SOUTH) {
						if(i - 1 < 0) {
							is_rand_direction_valid = 0;
						}
					} else if(rand_direction == EAST) {
						if(j - 1 < 0) {
							is_rand_direction_valid = 0;
						}
					} else if(rand_direction == WEST) {
						if(j + 1 >= taquin->nb_column) {
							is_rand_direction_valid = 0;
						}
					}
				} while(!is_rand_direction_valid);			


				if(rand_direction == SOUTH) {
					*swap_done += moveCell(taquin, &taquin->cells[i - 1][j]);
				} else if(rand_direction == NORTH) {
					*swap_done += moveCell(taquin, &taquin->cells[i + 1][j]);
				} else if(rand_direction == WEST) {
					*swap_done += moveCell(taquin, &taquin->cells[i][j + 1]);
				} else if(rand_direction == EAST) {
					*swap_done += moveCell(taquin, &taquin->cells[i][j - 1]);
				}
				break;
			}
		}
	}
}

int isTaquinEnded(Taquin taquin) {
	int i, j;
	for(i = 0; i < taquin.nb_line; i++) {
		for(j = 0; j < taquin.nb_column; j++) {
			if(taquin.cells[i][j].origin_line != i || taquin.cells[i][j].origin_column != j) {
				return 0;
			}
		}
	}
	return 1;
}
void freeTaquin(Taquin* taquin) {
	int i, j;
	for(i = 0; i < taquin->nb_line; i++) {
		for(j = 0; j < taquin->nb_column; j++) {
			MLV_free_image(taquin->cells[i][j].image);
		}
		free(taquin->cells[i]);
	}
	free(taquin->cells);

	freePlayerData(&taquin->player_data);

}
void drawTaquin(Taquin taquin) {
	
	int width, height;
	int i, j;
	MLV_Font* font;

	if(taquin.is_ended) {
		/* Draw the final image*/
		MLV_draw_image(taquin.image, taquin.x, taquin.y);
	} else {
		/* Draw all partial images*/
		for(i = 0; i < taquin.nb_line; i++) {
			for(j = 0; j < taquin.nb_column; j++) {
				if(taquin.cells[i][j].is_black_cell == 0) 
					MLV_draw_image(taquin.cells[i][j].image,taquin.cells[i][j].x,taquin.cells[i][j].y);
				/*else 
					MLV_draw_filled_rectangle(taquin.cells[i][j].x, taquin.cells[i][j].y, getCellWidth(taquin), getCellHeight(taquin), MLV_COLOR_BLACK);
				*/
				MLV_get_image_size(taquin.cells[i][j].image, &width, &height);
			}
		}

		for(i = 0; i < taquin.nb_line; i++) {
			for(j = 0; j < taquin.nb_column; j++) {
				MLV_draw_rectangle(MARGIN+getCellWidth(taquin)*i, MARGIN+getCellHeight(taquin)*j, width, height, MLV_COLOR_BLACK);
			}
		}
	}
	MLV_draw_rectangle(taquin.x-1, taquin.y-1, taquin.width+2, taquin.height+2, MLV_COLOR_BLACK);

	/*Draw player data*/
	drawPlayerData(taquin.player_data);

	if(taquin.is_ended) {
		font = MLV_load_font("resources/Retro.ttf", 30);
		MLV_draw_text_with_font(taquin.x + 10, taquin.y + 10, "Press 'SPACE' for MENU", font, MLV_COLOR_BLACK);
		MLV_free_font(font);
	}


}
void updateTaquin(Taquin* taquin, int* current_screen) {
	Cell *clicked_cell;
	int i,j;
	taquin->can_play = 1;





	/* Set positions for animation*/
	for(i = 0; i<taquin->nb_line; i++) {
		for(j = 0; j<taquin->nb_column; j++) {

			/*If movement is processing, cant play*/
			if(taquin->cells[i][j].y != taquin->cells[i][j].dest_y || taquin->cells[i][j].x != taquin->cells[i][j].dest_x) {
				taquin->can_play = 0;
			}
			
			/* Make y goes to dest_y slowly */
			if(taquin->cells[i][j].y < taquin->cells[i][j].dest_y + taquin->swap_speed && taquin->cells[i][j].y > taquin->cells[i][j].dest_y - CASE_SPEED) {
				taquin->cells[i][j].y = taquin->cells[i][j].dest_y;
			} else if(taquin->cells[i][j].y < taquin->cells[i][j].dest_y) {
				taquin->cells[i][j].y += taquin->swap_speed;
			} else if(taquin->cells[i][j].y > taquin->cells[i][j].dest_y) {
				taquin->cells[i][j].y -= taquin->swap_speed;
			} 

			/* Make x goes to dest_x slowly */
			if(taquin->cells[i][j].x < taquin->cells[i][j].dest_x + taquin->swap_speed && taquin->cells[i][j].x > taquin->cells[i][j].dest_x - CASE_SPEED) {
				taquin->cells[i][j].x = taquin->cells[i][j].dest_x;
			} else if(taquin->cells[i][j].x < taquin->cells[i][j].dest_x) {
				taquin->cells[i][j].x += taquin->swap_speed;
			} else if(taquin->cells[i][j].x > taquin->cells[i][j].dest_x) {
				taquin->cells[i][j].x -= taquin->swap_speed;
			}
		}
	}
	/* Listen click */
	if(!taquin->is_ended) clicked_cell = listenCellClick(taquin);
	else  {
		/* If space pressed, current screen change*/
		if(MLV_get_keyboard_state(MLV_KEYBOARD_SPACE) == MLV_PRESSED) {
			*current_screen = LEVEL_SELECTOR;
			freeTaquin(taquin);
			return;
		}
	}

	if(clicked_cell != NULL) {
		if(moveCell(taquin, clicked_cell)) {
			(&taquin->player_data)->movement_done +=1;
			if(isTaquinEnded(*taquin)) {
				(&taquin->player_data)->time_end = time(NULL);
				saveScore(taquin->player_data);
				taquin->is_ended = 1;
			}
		}
	}
	/*Randomizing grid*/
	if(taquin->swap_done < taquin->difficulty) 
		randomizeGrid(taquin, &taquin->swap_done);
	else 
		taquin->is_randomizing = 0;


}

int moveCell(Taquin* taquin, Cell *cell) {
	int current_cell_line, current_cell_column;
	int destination_cell_line, destination_cell_column;
	int cell_found = 0;
	Cell temp_cell;
	int i, j;
	int to_x, to_y, from_x, from_y;

	if(!taquin->can_play) {
		return 0;
	}
	if(cell->is_black_cell) {
		return 0;
	} 

	/* Get cell current position*/
	for(i = 0; i < taquin->nb_line; i++) {
		for(j = 0; j < taquin->nb_column; j++) {
			if(cell == &taquin->cells[i][j]) {
				current_cell_line = i;
				current_cell_column = j;
				cell_found = 1;
			}
			if((&taquin->cells[i][j])->is_black_cell) {
				destination_cell_line = i;
				destination_cell_column = j;
			}
		}
	}
	if(!cell_found) {
		return 0;
	}

	/* The cell must be close */
	if(
	!(
		(
			current_cell_column == destination_cell_column &&
			current_cell_line+1 == destination_cell_line
		)
		||
		(
			current_cell_column == destination_cell_column &&
			current_cell_line-1 == destination_cell_line
		)
		||
		(
			current_cell_column+1 == destination_cell_column &&
			current_cell_line == destination_cell_line
		)
		||
		(
			current_cell_column-1 == destination_cell_column &&
			current_cell_line == destination_cell_line
		)
	)
	) { 
		return 0;
	}

	/* Get destination position */
	to_x = taquin->cells[destination_cell_line][destination_cell_column].x;
	to_y = taquin->cells[destination_cell_line][destination_cell_column].y;
	from_x = taquin->cells[current_cell_line][current_cell_column].x;
	from_y = taquin->cells[current_cell_line][current_cell_column].y;

	/* Swap cells in the array*/
	temp_cell = taquin->cells[destination_cell_line][destination_cell_column];
	taquin->cells[destination_cell_line][destination_cell_column] = taquin->cells[current_cell_line][current_cell_column];
	taquin->cells[current_cell_line][current_cell_column] = temp_cell;
	
	/* Change position smoothly*/
	if(taquin->is_randomizing) {
		taquin->cells[current_cell_line][current_cell_column].dest_x = from_x;
		taquin->cells[current_cell_line][current_cell_column].x = from_x;
		taquin->cells[current_cell_line][current_cell_column].dest_y = from_y;
		taquin->cells[current_cell_line][current_cell_column].y = from_y;

		taquin->cells[destination_cell_line][destination_cell_column].dest_x = to_x;
		taquin->cells[destination_cell_line][destination_cell_column].x = to_x;
		taquin->cells[destination_cell_line][destination_cell_column].dest_y = to_y;
		taquin->cells[destination_cell_line][destination_cell_column].y = to_y;
	} else 
	{
		taquin->cells[current_cell_line][current_cell_column].dest_x = from_x;
		taquin->cells[current_cell_line][current_cell_column].dest_y = from_y;
		
		taquin->cells[destination_cell_line][destination_cell_column].dest_x = to_x;
		taquin->cells[destination_cell_line][destination_cell_column].dest_y = to_y;
	}

	return 1;
}

Cell* listenCellClick(Taquin *taquin) {
	int mouse_x, mouse_y;
	int i,j;
	Cell *cell = NULL;

	if(MLV_get_mouse_button_state(MLV_BUTTON_LEFT) != MLV_PRESSED) return cell;
	MLV_get_mouse_position(&mouse_x, &mouse_y);
	
	/* Check for each cells which one is on mouse_x and mouse_y*/
	for(i = 0; i < taquin->nb_line; i++){
		for(j = 0; j < taquin->nb_column; j++) {
			if(mouse_x >= taquin->cells[i][j].x && mouse_x <= taquin->cells[i][j].x + getCellWidth(*taquin) &&
			   mouse_y >= taquin->cells[i][j].y && mouse_y <= taquin->cells[i][j].y + getCellHeight(*taquin)) {
				cell = &taquin->cells[i][j];
			}
		}
	}

	return cell;
}