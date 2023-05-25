#include <stdio.h>
#include <string.h>

#include <readline/readline.h>
#include <readline/history.h>

#include "pile/pile.h"
#include "calculator/calculator.h"


int main(int argc, char *argv[]) {
    BinOperation* calculator = register_calculator();
    char* token;
    int input_value;
    int end = 0;
    char* line;

    printf("=== Calculator ===\n");
    printf("Operations :\n");
    printf("+ .... Addition\n");
    printf("- .... Soustraction\n");
    printf("* .... Multiplication\n");
    printf("^ .... Puissance\n");
    printf("! .... Factioriel\n");
    printf("p .... Modulo\n");
    printf("/ .... division\n");
    printf("X .... Integer to push in the calculator stack\n");

    printf("\nOptions :\n");
    printf("p .... Check last result\n");
    printf("c .... Empty the calculator stack\n");
    printf("a .... Check all the calculator stack\n");
    printf("r .... Reverse heads values\n");
    printf("q .... Quit\n");


    while(!end) {


        line = readline("");

        for(token = strtok(line, " "); token != NULL; token=strtok(NULL, " ")) {
            if( token[0] == '+' || 
                token[0] == '-' || 
                token[0] == '*' || 
                token[0] == '!' || 
                token[0] == '^' || 
                token[0] == '%' || 
                token[0] == '/' ) {
                if(size_stack() >= 2) 
                    push_stack(calculator[(int)token[0]](pop_stack(),pop_stack()));
                else 
                    printf("There is not enough values in the calculator stack to make this operation !\n");

            } else if(token[0] == 'q') {
                printf("Goodbye !\n");
                end = 1;

            } else if(token[0] == 'p')  {
                if(size_stack() == 0) {
                    printf("The calculator stack is empty !\n");
                } else {
                    printf("Head of the calculator stack: %d\n", head_stack());

                }

            } else if(token[0] == 'c') {
                printf("Calculator stack is now empty.\n");
                empty_stack();

            } else if(token[0] == 'a') {
                printf("Stack of the calculator : (%d element(s))\n", size_stack());
                print_stack();
            }
            else if(token[0] == 'r') {
                if(size_stack() >= 2) {
                    reverse_head_stack();
                    printf("Top values of the calculator stack head were reversed\n");
                } else {
                    printf("There is not enough values in the calculator stack !\n");
                }

            }else {
                input_value = atoi(token);
                if(input_value != 0) 
                    push_stack(input_value);

            }
        }

        free(line);
    }

    clear_history();
    free(calculator);
    return 1;
}
