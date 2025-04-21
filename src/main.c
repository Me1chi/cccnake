#include <stdio.h>
#include "raylib.h"
#include "logic.h"
#include "clock.h"

#define SCREENWIDTH 600
#define SCREENHEIGHT 600

#define SNAKESEGSIZE 30
#define SNAKESPEED 0.3
int main(void) {
    
    // Initialize the game snake
    Snake snake = init_snake(Right);
    snake = add_snake_node(snake);

    InitWindow(SCREENWIDTH, SCREENHEIGHT, "CCCnake");

    SetTargetFPS(30);

    SnakeNode *aux;

    while (!WindowShouldClose()) {

        // GAME LOGIC AND UPDATES 
        snake = change_snake_direction(snake);
        snake = move_snake(snake, SNAKESPEED);

        //SUBSTITUTE THIS BY THE SNAKE EATING THE APPLE
        if (timer(1)) {
            add_snake_node(snake);
        }
        // GAME DRAWING 
        BeginDrawing();

        ClearBackground(DARKGRAY);

        aux = snake.ptr;
        while (aux != NULL) {

            // THIS WEIRD WAY OF DRAWING WILL REMAIN UNTIL I FIND A NEW WAY OF DOING IT
            DrawRectangle(SNAKESEGSIZE*(int)aux->x, SNAKESEGSIZE*(int)aux->y, SNAKESEGSIZE, SNAKESEGSIZE, RED);
            printf("%f %f\n", snake.ptr->x, snake.ptr->y);

            aux = aux->next;
        }

        EndDrawing();
    }

    return 0;
}
