#include <stdio.h>
#include <stdlib.h>

/* Bibliothèque pour gérer l'aléatoire*/
#include <time.h>

/* Constantes nécéssaire au programme */
#include "include/data.h"
#include "include/taquin.h"
#include "include/constants.h"
#include "include/menu.h"

/* Permet de récupérer les signaux*/
#include <signal.h>
#include <unistd.h>


void freeMemory();
void printUsage(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    int current_screen = LEVEL_SELECTOR;
    LevelSettings* level_settings;
    Taquin taquin;

	srand(time(NULL)); 
    signal(SIGINT, freeMemory); 

    /* Init window */
    MLV_create_window(PROJECT_NAME, PROJECT_NAME, WIN_WIDTH, WIN_HEIGHT);

    /* Init settings */
    level_settings = initLevelSettings();


    /* Game loop for each frame*/
    while(current_screen != END) {
        MLV_clear_window(MLV_COLOR_PURPLE);

        if(current_screen == GAME_SCREEN) {
            /* Update taquin data*/
            updateTaquin(&taquin, &current_screen);

            /* Draw elements*/
            drawTaquin(taquin);
        } else if(current_screen == LEVEL_SELECTOR) {
            /* Listen clicks on menu */
            listenMenuEvents(level_settings, 3, &current_screen, &taquin);

            /* Draw menu */
            drawMenu(level_settings, 3);
        }


        MLV_update_window();
        /* Wait frame ends */
        MLV_wait_milliseconds(12);
    }


    /* Free memory */
    freeLevelSettings(level_settings, 3);
    freeMemory();
    return EXIT_SUCCESS;
}

void printUsage(int argc, char* argv[])
{
    printf("Usage & options:\n");
    printf("%s                       Start taquin with a default image.\n", argv[0]);
    exit(EXIT_FAILURE);
}


void freeMemory()
{

}