#include <stdio.h>
#include <stdlib.h>
#include "swap.h"


void swap_mem(void* z1, void* z2, size_t size) {
    char tmp;
    int i;

    for(i = 0; i < size; i++) {
        tmp = *( (char*)z1 + i );
        *( (char*)z1 + i ) = *( (char*)z2 + i );
        *( (char*)z2 + i ) = tmp;

    }


}