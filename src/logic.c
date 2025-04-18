#include "logic.h"

Snake add_snake_node(Snake snake) {

    SnakeNode *aux;
    SnakeNode *snake_tail = (SnakeNode *)malloc(sizeof(SnakeNode));

    if (snake.ptr == NULL) {
        snake.ptr = snake_tail;
    } else {
        for (aux = snake.ptr; aux->next != NULL; aux = aux->next)

        aux->next = snake_tail;
    } 

    return snake;
}

// PRA DEIXAR ANOTADO, PRA CADA FRAME DO JOGO, O NODO ANTERIOR RECEBE A POSICAO DO NODO DA FRENTE, 
// DESSA FORMA ELE NAO PRECISA TER UMA DIRECAO PRA ANDAR, SO O PRIMEIRO (teoricamente nem de uma posicao ele preciasaria
// mas dai ja fica meio feio)

void move_snake(Snake *snake) {
    
    
}
