
typedef struct {
    int num_level;
    int nb_line;
    int nb_col;
    MLV_Image* image;
    int width;
    int height;
    int x;
    int y;
    int is_over;
    char* score_str;
} LevelSettings;


LevelSettings* initLevelSettings();
void freeLevelSettings(LevelSettings* levelSettings, int nb_levels);
void listenMenuEvents(LevelSettings* levelSettings, int nb_levels, int* current_screen, Taquin *taquin);
void drawMenu(LevelSettings* levelSettings, int nb_levels);