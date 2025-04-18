#pragma once
#include <stdlib.h>

typedef enum {
    Left,
    Right,
    Up,
    Down,

} Going;

typedef struct SnakeNode SnakeNode;

struct SnakeNode {
    int x;
    int y;

    SnakeNode *next;

};

typedef struct {
    int x;
    int y;
    
    SnakeNode *ptr;

} Snake;


