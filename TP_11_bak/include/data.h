#include <MLV/MLV_all.h>

typedef struct {
    int start_timestamp;
    int time_end;
    int movement_done;
    int level_num;
    MLV_Font* font;
} PlayerData;

typedef struct _Score{
    int time;
    int movements;
    struct _Score* next;
} Score;


#define SCORE_FILE_PATH "data/score_%d.txt"

PlayerData initPlayerData(int level_num);
void drawPlayerData(PlayerData player_data);
void freePlayerData(PlayerData *player_data);
Score* getLevelScores(int level_num);
void freeScore(Score* score);
void sortByTime(Score* score_list);
char* scoreToString(int level_num);
void saveScore(PlayerData playerData);