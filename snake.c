#include "raylib.h"
#include "snake.h"

struct snake create_snake(Vector2 start_position) {
    struct snake snake = {
        .length = 1,
        .width = 20,
        .direction = 'r',
    };
    snake.body[0] = start_position;
    return snake;
}

void turn_snake(struct snake *snake) {
    switch (snake->direction) {
        case 'u':
        case 'd':
            if (IsKeyDown(KEY_LEFT)) snake->direction = 'l';
            if (IsKeyDown(KEY_RIGHT)) snake->direction = 'r';
            break;
        case 'l':
        case 'r':
            if (IsKeyDown(KEY_UP)) snake->direction = 'u';
            if (IsKeyDown(KEY_DOWN)) snake->direction = 'd';
            break;
    }
};

void update_snake(struct snake *snake) {
    int move_distance = snake->width;
    Vector2 *head = &snake->body[0];
    for (int i = snake->length - 1; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
    }

    switch (snake->direction) {
        case 'u':
            head->y -= move_distance;
            break;
        case 'd':
            head->y += move_distance;
            break;
        case 'l':
            head->x -= move_distance;
            break;
        case 'r':
            head->x += move_distance;
            break;
    }
}

void eat_pellet(struct snake *snake) {
    snake->body[snake->length] = snake->body[snake->length - 1];
    snake->length += 1;
}

void draw_snake(struct snake snake) {
    for (int i = 0; i < snake.length; i++) {
        DrawRectangleV(snake.body[i], (Vector2){snake.width, snake.width}, WHITE);
    }
};