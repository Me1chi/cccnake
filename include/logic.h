typedef enum {
    Left,
    Right,
    Up,
    Down,

} Going;

typedef struct SnakeNode SnakeNode;

struct SnakeNode {
    float x;
    float y;

    SnakeNode *next;

};

typedef struct {
    Going direction; 
    SnakeNode *ptr;

} Snake;

Snake init_snake(Going direction);

Snake add_snake_node(Snake snake);

Snake move_snake(Snake snake, float snake_speed);

Snake change_snake_direction(Snake snake);
