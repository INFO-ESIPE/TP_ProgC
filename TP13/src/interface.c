#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include "../include/dame.h"
#include "../include/interface.h"

void create_window() {
    MLV_create_window("Dame", "Dame", WIDTH, HEIGHT);
}

void listen_action(Board *board, Pile *pile) {
    int mouse_x, mouse_y, position;
    MLV_get_mouse_position(&mouse_x, &mouse_y);
    if(MLV_get_mouse_button_state(MLV_BUTTON_LEFT ) == MLV_PRESSED) {
        position = coords_to_position(mouse_x, mouse_y);
        if(position != -1) {
            if(set_positive_bit_ULI(board, position)) {
                push(pile, position);
            }  
        } 
    }

    if(size(pile) > 0) {
        if(MLV_get_keyboard_state(MLV_KEYBOARD_z) == MLV_PRESSED && MLV_get_keyboard_state(MLV_KEYBOARD_LCTRL) == MLV_PRESSED) {
            set_negative_bit_ULI(board, pop(pile));
            board = 0;
        }
    }
}

int coords_to_position(int x, int y) {
    int case_size = CASE_SIZE-MARGIN;
    if(x > case_size*BOARD_SIZE || y > case_size*BOARD_SIZE) return -1;
    
    return (x/case_size)*BOARD_SIZE + y/case_size;
}

void draw_board(Board *board, Pile* pile, MLV_Image *dame) {
    int i, j, text_width, text_height;
    int case_size = CASE_SIZE-MARGIN;

    MLV_clear_window(MLV_COLOR_LIGHT_GRAY);

    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if((i+j)%2 == 0) 
                MLV_draw_filled_rectangle(i*case_size, j*case_size, case_size, case_size, MLV_COLOR_LIGHT_GRAY);
            else
                MLV_draw_filled_rectangle(i*case_size, j*case_size, case_size, case_size, MLV_COLOR_GRAY);
        
            if(bit_value_ULI(*board, i*BOARD_SIZE+j) == 1) {
                MLV_resize_image(dame, case_size, case_size);
                MLV_draw_image(dame, i*case_size, j*case_size);
            }
        }
    }

    MLV_draw_line(case_size*BOARD_SIZE, 0, case_size*BOARD_SIZE, (case_size*BOARD_SIZE), MLV_COLOR_BLACK);
    MLV_draw_line(case_size*BOARD_SIZE+case_size/2, 0, case_size*BOARD_SIZE+case_size/2, HEIGHT, MLV_COLOR_BLACK);

    MLV_draw_line(0, case_size*BOARD_SIZE, case_size*BOARD_SIZE, (case_size*BOARD_SIZE), MLV_COLOR_BLACK);
    MLV_draw_line(0, (case_size*BOARD_SIZE) + case_size/2, 0,case_size*BOARD_SIZE+case_size/2, MLV_COLOR_BLACK);
    
    text_width = -20;
    text_height = -20;
    for(i = 0; i < BOARD_SIZE; i++) {
        MLV_draw_text(
            case_size*BOARD_SIZE+case_size/2+text_width, 
            i*case_size+case_size/2+text_height, 
            "%d", MLV_COLOR_BLACK, i);
        MLV_draw_text(
            i*case_size+case_size/2, 
            case_size*BOARD_SIZE+case_size/2 + text_height, 
            "%d", MLV_COLOR_BLACK, i);
    }

    if(size(pile) != 0) {
        /* Button to cancel*/
        MLV_draw_rectangle(
            case_size*BOARD_SIZE+case_size/2 + WIDTH/10,
            HEIGHT/10,
            case_size*2+10, case_size/2, MLV_COLOR_BLACK);

        MLV_draw_text(
            case_size*BOARD_SIZE+case_size/2 + WIDTH/10 + case_size/2 - 23,
            HEIGHT/10 + case_size/2 - 23,
            "CTRL+Z to Cancel", MLV_COLOR_BLACK);
    }
    
    if(free_spaces(board) == 0) {
        MLV_draw_text(
            case_size*BOARD_SIZE+case_size/2 + WIDTH/10 + case_size/2 - 23,
            (HEIGHT/10 + case_size/2) + 50,
            positive_bits(*board) != 8 ? "You loose :(" : "You win !", MLV_COLOR_BLACK);
    }
    

    MLV_actualise_window();
}