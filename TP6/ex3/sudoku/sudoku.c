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
int testNum;

/* Fonction pour remplir la grille de sudoku*/
void initialize_empty_board(Board grid){
    int testX, testY, value;
    testNum = 0;


    testX = 0;
    testY = 1;
    value = 1;
    can_play_value(grid, testX, testY, value);


   permutations(grid);
}


/*Fonction affichant toutes les permutations avec le tableau array (initié à 0)*/
void permutations(Board grid)
{
	int i, j, k;


    testNum++;
	/*Test de la grille */
    /*if(is_correct_grid(grid) == 1)*/
    if(is_grid_full(grid) == 1)
     {
        printf("\nSuccess after %d tests :", testNum);
        print_board(grid);
        exit(1);
    } 
    if(testNum%1000 == 0) {
        printf("Searching solution... (test n°%d)\n", testNum);
        print_board(grid);
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
                        grid[i][j] = k;
                
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
        printf("grid[%d][%d] = %d (test : %d) \n", x, y, grid[x][y], value);

    int i,j;
    int subCellX, subCellY;
    if(grid[x][y] != 0)
    {
        printf("case prise :\n");
        return 0;
    }
    if(value > 9 || value < 1) 
    {
        printf("Valeur incorrecte :\n");
        return 0;
    }

    /* Vérification des cases voisines*/
    if(x >= 0 && x <= 2) subCellX = 0;
    else if (x >= 3 && x <= 5) subCellX = 1;
    else if (x >= 6 && x <= 8) subCellX = 2;

    if(y >= 0 && y <= 2) subCellY = 0;
    else if (y >= 3 && y <= 5) subCellY = 1;
    else if (y >= 6 && y <= 8) subCellY = 2;

    for(i = 0; i<3; i++)
        for(j = 0; j<3; j++ )
            if(grid[i+(subCellX*3)][j+(subCellY*3)] == value && (i+(subCellX*3) != x && j+(subCellY*3) != y)) {
                printf("Voisin\n");

                return 0;   
            }

    /* Vérification ligne colonnes*/
    for(i = 0; i < 9; i++) {
        if(grid[x][i] == value && (i != y)) {
            printf("Colonne\n");
            return 0;
        }
    }
    
    for(i = 0; i < 9; i++){
        if(grid[i][y] == value && (i != x)) {
                printf("Ligne\n");

            return 0;
        } 
    }
    printf("C'est bon\n");

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
