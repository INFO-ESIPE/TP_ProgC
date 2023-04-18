#include <time.h>
#include <stdlib.h>

#include "../include/data.h"

PlayerData initPlayerData(int level_num) {
    PlayerData player_data;
    player_data.start_timestamp = time(NULL);
    player_data.movement_done = 0;
    player_data.time_end = -1;
    player_data.level_num = level_num;
    player_data.font = MLV_load_font("./resources/Retro.ttf", 20);

    return player_data;
}


void drawPlayerData(PlayerData player_data) {
    int minutes, seconds;
    char time_str[100];
    char movement_str[100];

    /* Compute time */

    if(player_data.time_end == -1) {
        seconds = time(NULL) - player_data.start_timestamp;
        minutes = seconds / 60;
        seconds = seconds % 60;
    } else {    
        seconds = player_data.time_end - player_data.start_timestamp;
        minutes = seconds / 60;
        seconds = seconds % 60;
    }

    /* Draw time */
    sprintf(time_str, "%d:%d", minutes, seconds);
    MLV_draw_text_with_font(
        10,
        10,
        time_str,
        player_data.font,
        MLV_COLOR_WHITE
    );

    /* Draw movement */
    sprintf(movement_str, "%d", player_data.movement_done);
    MLV_draw_text_with_font(
        10,
        30,
        movement_str,
        player_data.font,
        MLV_COLOR_WHITE
    );

}

void freePlayerData(PlayerData* player_data) {
}


void sortByTime(Score* score_list) {
    Score *current_score = score_list;
    Score *next_score;
    int tmp_movements;
    int tmp_time;

    while(current_score != NULL) {
        next_score = current_score->next;
        while(next_score != NULL) {
            if(current_score->time > next_score->time) {
                tmp_movements = current_score->movements;
                tmp_time = current_score->time;

                current_score->movements = next_score->movements;
                current_score->time = next_score->time;

                next_score->movements = tmp_movements;
                next_score->time = tmp_time;
            }
            next_score = next_score->next;
        }
        current_score = current_score->next;
    }
}

char* scoreToString(int level_num) {
    char* score_str = malloc(2500);
    char line[25];
    int seconds, minutes;
    Score* score = getLevelScores(level_num);   
    Score *current_score = score;
    score_str[0] = '\0';	

    /*sortByTime(score);*/
    
    while(current_score->next != NULL) {
        seconds = current_score->time;
        minutes = seconds / 60;
        seconds = seconds % 60;

        sprintf(line, "%d moves | %d:%d\n", current_score->movements, minutes, seconds);
        strcat(score_str, line);

        current_score = current_score->next;
    } 


    freeScore(score);
    return score_str;
}


Score* getLevelScores(int level_num) {
    char filename[100];
    FILE* file;
    Score *score;
    Score *current_score;

    sprintf(filename, SCORE_FILE_PATH, level_num);

    file = fopen(filename, "r");
    if(file == NULL) {
        return NULL;
    }

    score = malloc(sizeof(Score));
    current_score = score;

    while(fscanf(file, "%d %d", &current_score->movements, &current_score->time) == 2) {
        current_score->next = malloc(sizeof(Score));
        current_score = current_score->next;
    }

    current_score->next = NULL;

    fclose(file);
    return score;
}

void freeScore(Score* score) {
    Score* current_score = score;
    Score* next_score = score->next;

    while(next_score != NULL) {
        free(current_score);
        current_score = next_score;
        next_score = next_score->next;
    }
    free(current_score);
}

void saveScore(PlayerData playerData) {
    char filename[100];
    FILE* file;

    sprintf(filename, SCORE_FILE_PATH, playerData.level_num);

    file = fopen(filename, "a");
    fprintf(file, "%d %d\n", playerData.movement_done, playerData.time_end - playerData.start_timestamp);
    fclose(file);
}   