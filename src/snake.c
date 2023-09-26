#include "raylib.h"
#include "snake.h"

const char LEFT = 'l';
const char RIGHT = 'r';
const char UP = 'u';
const char DOWN = 'd';

struct snake create_snake(Vector2 start_position) {
    struct snake snake = {
        .length = 1,
        .width = 20,
        .direction = RIGHT,
        .turning = false,
    };
    snake.body[0] = start_position;
    return snake;
}

void turn_snake(struct snake *snake, char direction) {
    if (snake->turning) return;
    switch (snake->direction) {
        case UP:
        case DOWN:
            if (direction == LEFT) {
                snake->direction = LEFT;
                snake->turning = true;
            }
            if (direction == RIGHT) {
                snake->direction = RIGHT;
                snake->turning = true;
            }
            break;
        case LEFT:
        case RIGHT:
            if (direction == UP) {
                snake->direction = UP;
                snake->turning = true;
            }
            if (direction == DOWN) {
                snake->direction = DOWN;
                snake->turning = true;
            }
            break;
    }
}

void update_snake(struct snake *snake, struct game_window window) {
    int move_distance = snake->width;
    Vector2 *head = &snake->body[0];
    for (int i = snake->length - 1; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
    }

    switch (snake->direction) {
        case UP:
            head->y -= move_distance;
            if (head->y < 0) head->y = window.height - snake->width;
            break;
        case DOWN:
            head->y += move_distance;
            if (head->y > window.height - snake->width) head->y = 0;
            break;
        case LEFT:
            head->x -= move_distance;
            if (head->x < 0) head->x = window.width - snake->width;
            break;
        case RIGHT:
            head->x += move_distance;
            if (head->x > window.width - snake->width) head->x = 0;
            break;
    }
    snake->turning = false;
}

void draw_snake(struct snake snake) {
    DrawRectangleV(snake.body[0], (Vector2){snake.width, snake.width}, LIGHTGRAY);
    for (int i = 1; i < snake.length; i++) {
        DrawRectangleV(snake.body[i], (Vector2){snake.width, snake.width}, WHITE);
    }
}
