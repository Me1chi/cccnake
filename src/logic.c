#include <stdlib.h>
#include <stdio.h>
#include "logic.h"
#include "raylib.h"

Snake init_snake(Going direction) {
    Snake new_snake = {0};

    new_snake.direction = direction;
    new_snake.alive = true;
    new_snake.ptr = NULL;

    return new_snake;
}

Snake add_snake_node(Snake snake) {
    // The node is added but its position must be updated within the move_snake function
    SnakeNode *aux;
    SnakeNode *snake_tail = (SnakeNode *)malloc(sizeof(SnakeNode));

    // Initializing the tail at (-1, -1). So it does not flash appear on the screen
    snake_tail->next = NULL;
    snake_tail->x = -1;
    snake_tail->y = -1;

    if (snake.ptr == NULL) {
        // Changing the the position to (1,1) if it is the 1st node
        snake_tail->x = 1;
        snake_tail->y = 1;
        snake.ptr = snake_tail;
    } else {
        aux = snake.ptr;

        while (aux->next != NULL)
            aux = aux->next;

        aux->next = snake_tail;
    } 

    return snake;
}

int test_direction(char x_or_y, Going direction) {
    int dir_var = 0;

    switch (direction) {
        case Left:
            if (x_or_y == 'x')
                dir_var = -1;
            else if (x_or_y == 'y') 
                dir_var = 0;

            break;
        case Right:
            if (x_or_y == 'x')
                dir_var = 1;
            else if (x_or_y == 'y')
                dir_var = 0;

            break;
        case Up:
            if (x_or_y == 'x')
                dir_var = 0;
            else if (x_or_y == 'y')
                dir_var = -1;

            break;
        case Down:
            if (x_or_y == 'x')
                dir_var = 0;
            else if (x_or_y == 'y')
                dir_var = 1;
            break;
    }

    return dir_var;
}

Snake move_snake(Snake snake) {
    
    SnakeNode *aux;
    
    Vector2 prev_data = {0};
    Vector2 prev_data_aux = {0};

    if (snake.ptr != NULL) {

        for (aux = snake.ptr; aux->next != NULL; aux = aux->next) {
 
            prev_data_aux.x = aux->x;
            prev_data_aux.y = aux->y;

            if (aux != snake.ptr) {

                aux->x = prev_data_aux.x;
                aux->y = prev_data_aux.y;

            }
        }

        aux = snake.ptr;
        prev_data.x = aux->x;
        prev_data.y = aux->y;

        while (aux->next != NULL) {

            prev_data_aux.x = prev_data.x;
            prev_data_aux.y = prev_data.y;

            aux = aux->next;

            prev_data.x = aux->x;
            prev_data.y = aux->y;

            aux->x = prev_data_aux.x;
            aux->y = prev_data_aux.y; 

        }

        snake.ptr->x += test_direction('x', snake.direction);
        snake.ptr->y += test_direction('y', snake.direction);

    }

    return snake;
}

Snake change_snake_direction(Snake snake) {
    Going new_direction = snake.direction;

    if (IsKeyPressed(KEY_LEFT) && snake.direction != Right) {
        new_direction = Left;
    }

    if (IsKeyPressed(KEY_RIGHT) && snake.direction != Left) {
        new_direction = Right;
    }
    
    if (IsKeyPressed(KEY_UP) && snake.direction != Down) {
        new_direction = Up;
    }

    if (IsKeyPressed(KEY_DOWN) && snake.direction != Up) {
        new_direction = Down;
    }

    snake.direction = new_direction;

    return snake;
    
}
