#ifndef SNAKE_H
#define SNAKE_H

#include "raylib.h"
#include "window.h"

#define MAX_SNAKE_LENGTH 256

struct snake {
    Vector2 body[MAX_SNAKE_LENGTH];
    int length;
    int width;
    char direction;
};

struct snake create_snake(Vector2 start_position);
void turn_snake(struct snake *snake);
void update_snake(struct snake *snake, struct game_window);
void draw_snake(struct snake snake);

#endif // SNAKE_H
