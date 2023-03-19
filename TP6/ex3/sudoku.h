#define CASE_SIZE 10


#define START_SUDOKU_X 50
#define START_SUDOKU_Y 50

#define START_SELECTOR_X 500
#define START_SELECTOR_Y 500


#define CLICK_NULL 0
#define CLICK_GRID 1
#define CLICK_SELECTOR 2

void main()
{
	while(1)
	{
		int mouseX, mouseY;
		wait_mouse(&mouseX, &mouseY);

		int where_the_user_clicked = CLICK_NULL;

		int currentSelectedCaseX = -1;
		int currentSelectedCaseY = -1;
		int selected_value

		printf("%d - %d\n", mouseX, mouseY);
		Board myBoard;

		fread_board("grid1.txt", myBoard)

		for(int i = 0; i < 9; i++)
		{
			for(int j = 0; j < 9; j++)
			{
				if(mouseX > START_SUDOKU_X+ CASE_SIZE*i && 
					mouseX < START_SUDOKU_X+ (CASE_SIZE*(i+1)) &&
					mouseY > START_SUDOKU_Y+ CASE_SIZE*j && 
					mouseY < START_SUDOKU_Y+ (CASE_SIZE*(j+1))
				{
						printf("Clique sur la grille %d %d\n", i, j);
						currentSelectedCaseX = i;
						currentSelectedCaseY = j;
						where_the_user_clicked = CLICK_GRID;
						draw_num_selector()

				}
			}
		}

		if(where_the_user_clicked != CLICK_GRID)
		{
			if(getSlotChoice(mouseX, mouseY, selected_value))
				myBoard[currentSelectedCaseX][currentSelectedCaseY] = selected_value

		
		}








	}

}

draw_num_selector(int x, int y)
{
	/*Code qui dessine un truc 3*3 avec des numéros*/


}

int getSlotChoice(int mouseX, int mouseY, int* selected_value)
{
    int i,j, k;
    
    k = 1;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
        {
            if(
                mouseX > MARGIN_LEFT*2 + SLOT_SIZE*9 + (j*SLOT_SIZE) && mouseX < MARGIN_LEFT*2 + SLOT_SIZE*9 + ((j+1)*SLOT_SIZE) &&
                mouseY > MARGIN_TOP + SLOT_SIZE*3 + (i*SLOT_SIZE) && mouseY < MARGIN_TOP + SLOT_SIZE*3 + ((i+1)*SLOT_SIZE)
            ) {
                *selected_value = k;
                return 1;
            }
            if(mouseX > MARGIN_LEFT*2 + SLOT_SIZE*10 -1 &&  mouseX < MARGIN_LEFT*2 + SLOT_SIZE*10 -1 + SLOT_SIZE+2 &&
               mouseY >MARGIN_TOP+ SLOT_SIZE*2 - 10 -1 &&  mouseY < MARGIN_TOP+ SLOT_SIZE*2 - 10 -1 + SLOT_SIZE+2
            ) {
                *selected_value = 0;
                return 1;
            }
            k++;
        }
    return 0;
}