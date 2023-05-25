#include <stdio.h>

#include <readline/readline.h>
#include <readline/history.h>

#include "calculator/calculator.h"


int main(int argc, char *argv[]) {
    BinOperation* calculator = register_calculator();
    printf("2+3=%d\n", calculator['+'](2,3));

    
    while(true) {
        
        char* line = readline();
        
        add_history(line);
        printf("You entered: %s\n", line);
        free(line);
    }


    return 1;
}
