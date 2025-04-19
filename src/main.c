#include <stdio.h>
#include "raylib.h"
#include "logic.h"

int main(void) {
    
    Snake my_snake = init_snake(Right);

    my_snake = add_snake_node(my_snake);
    my_snake = add_snake_node(my_snake);
    my_snake = add_snake_node(my_snake);
    my_snake.ptr->x = 20;
    my_snake.ptr->y = 30;

    InitWindow(600, 600, "Minha janela");

    SetTargetFPS(30);

    SnakeNode *aux;

    while (!WindowShouldClose()) {

        for(aux = my_snake.ptr; aux->next != NULL; aux = aux->next) {
            printf("Meu nodo x: %d, y: %d\n", aux->x, aux->y);
        }
        printf("my snake.ptr = %p\n", my_snake.ptr->next);


        my_snake = add_snake_node(my_snake);
        move_snake(my_snake);

        BeginDrawing();

        ClearBackground(DARKGRAY);

        DrawRectangle(300, 300, 30, 30, RED);

        EndDrawing();
    }

    return 0;
}
