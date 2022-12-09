#include <stdio.h>

#include "sudoku.h"
#include "in_out.h"

int main(int argc, char* argv[]){
  Board B;

  fread_board(argv[1], B);
  print_board(B);
  initialize_empty_board(B);
  /*print_board(B);*/

  return 0;
}
