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
    Going direction; 
    SnakeNode *ptr;

} Snake;

Snake init_snake(Going direction);

Snake add_snake_node(Snake snake);

void move_snake(Snake snake);
