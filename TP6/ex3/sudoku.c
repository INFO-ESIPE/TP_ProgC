/*
	Programme de remplissage de la grille sudoku (TP6/EX3)
	Max Ducoudré - INFO1
*/

#include <stdio.h>
#include <stdlib.h>

#include "sudoku.h"

/*Déclaration des fonctions*/
void permutations(Board grid);
int can_play_value(Board grid, int x, int y, int value);
int is_correct_grid(Board grid);
int is_grid_full(Board grid);
int sudokuSolver(Board grid, int x, int y);


/* Fonction permettant d'afficher la grille grid résolue */
void initialize_empty_board(Board grid){

    sudokuSolver(grid, 0, 0);

    printf("Grille finale :");
    print_board(grid);
    if(is_grid_full(grid)) printf("Aucune erreur sur la grille\n");
    else printf("Erreur(s) détécté(s) sur la grille !\n");
}



/*Fonction permettant de résoudre le sudoku "grid"*/
int sudokuSolver(Board grid, int x, int y)
{
    int k;
    if (x == 9 - 1 && y == 9) return 1;

    if(y == 9) {
        x++;
        y = 0;
    }

    if (grid[x][y] > 0) return sudokuSolver(grid, x, y + 1);

    for(k = 1; k <= 9; k++) {
        if(can_play_value(grid, x, y, k))
        {
            grid[x][y] = k;
            if(sudokuSolver(grid, x, y+1)) return 1; 
        }
        grid[x][y] = 0;
    }
    return 0;


}

/* Fonction permettant de résoudre le sudoku (fonctionne pas)*/
void permutations(Board grid)
{
	int i, j, k;


	/*Test de la grille */
    /*if(is_correct_grid(grid) == 1)*/
    if(is_grid_full(grid) == 1)
     {
        printf("\nSuccess ! ");
        print_board(grid);
        exit(1);
    } 

	for(i = 0; i < 9; i++) 
    {
        for(j = 0; j < 9; j++) 
        {
            if(grid[i][j] == 0) 
            {
                for(k = 1; k <= 9; k++)
                {
                    if(can_play_value(grid, i, j, k))
                    {
                        grid[i][j] = k;
                    }
                    permutations(grid);
                    grid[i][j] = 0;
                }
            }
        }
    }

}

/*Permet de vérifier si une grille est valide*/
int is_correct_grid(Board grid)
{
    int i, j;
    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            if(can_play_value(grid, i, j, grid[i][j]) == 0) return 0;
        }
    }
    return 1;    
}

/*Permet de vérifier si une grille est pleine ou non*/
int is_grid_full(Board grid)
{
    int i, j;

    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            if(grid[i][j] == 0) return 0;
        }
    }
    return 1;  
}

/*Fonction qui renvoie 1 si on peux jouer la valeur value à l'emplacement x y ou 0 si ce n'est pas possible*/
int can_play_value(Board grid, int x, int y, int value)
{
    int i,j;

    /*Vérification des arguments*/
    if(grid[x][y] != 0)
    {
        return 0;
    }
    if(value > 9 || value < 1) 
    {
        return 0;
    }

    /* Vérification des cases voisines*/
    for(i = 0; i<3; i++)
    {
        for(j = 0; j<3; j++)
        {
            if(grid[x+((x/3)*3)][y+((y/3)*3)] == value)
            {
                return 0;
            }
        }
    }

    /* Vérification ligne colonnes*/
    for(i = 0; i < 9; i++) {
        if(grid[x][i] == value && (i != y)) {
            return 0;
        }
    }
    
    for(i = 0; i < 9; i++){
        if(grid[i][y] == value && (i != x)) {
            return 0;
        } 
    }

    return 1;

}

/* Fonction pour afficher la grille de sudoku*/
void print_board(Board grid){
    int i,j;

    for(i = 0; i < 9; i++)
    {
        if(i%3 == 0) printf("\n|---------|---------|---------|");
        printf("\n");
        for(j = 0; j < 9; j++)
        {
            if(j == 0) printf("|");
            printf(" %d ", grid[i][j]);
            if(j%3 == 2) printf("|");

        }

    }
        if(i%3 == 0) printf("\n|---------|---------|---------|\n");
}
