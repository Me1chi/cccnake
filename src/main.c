#include <stdio.h>
#include "logic.h"

int main(void) {
    
    Snake my_snake = {
        20,
        30,
        NULL,
    };

    printf("My snake x: %d\n My snake y: %d. My snake next node: %p\n", my_snake.x, my_snake.y, my_snake.ptr);

    return 0;
}
