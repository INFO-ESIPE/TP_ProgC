/*
	Programmation C - TP11
	Max Ducoudré - INFO1
*/
#ifndef TAQUIN_H
#define TAQUIN_H
#include <MLV/MLV_all.h>

typedef struct {
	int img_width,
	int img_height,
	int cell_width,
	int cell_height,
	int column_nb,
	int line_nb
} TaquinData;



int prepareImage(TaquinData taquin_data);
int prepareTaquin(int nb_col, int nb_line, int win_width, int win_height, char* image_path, int difficulty);


#endif
