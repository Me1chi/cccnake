#include <stdlib.h>
#include <stdio.h>
#include "logic.h"
#include "raylib.h"

Snake init_snake(Going direction) {
    Snake new_snake = {0};

    new_snake.direction = direction;
    new_snake.ptr = NULL;

    return new_snake;
}

Snake add_snake_node(Snake snake) {
    // The node is added but its position must be updated within the move_snake function
    SnakeNode *aux;
    SnakeNode *snake_tail = (SnakeNode *)malloc(sizeof(SnakeNode));

    snake_tail->next = NULL;

    if (snake.ptr == NULL) {
        snake.ptr = snake_tail;
    } else {
        aux = snake.ptr;

        while (aux->next != NULL)
            aux = aux->next;

        aux->next = snake_tail;
    } 

    return snake;
}

// PRA DEIXAR ANOTADO, PRA CADA FRAME DO JOGO, O NODO ANTERIOR RECEBE A POSICAO DO NODO DA FRENTE, 
// DESSA FORMA ELE NAO PRECISA TER UMA DIRECAO PRA ANDAR, SO O PRIMEIRO (teoricamente nem de uma posicao ele preciasaria
// mas dai ja fica meio feio)

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

void move_snake(Snake snake) {
    
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

    
}
