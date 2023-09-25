#include "raylib.h"
#include "window.h"
#include "snake.h"

void process_input(struct game_window *window, struct snake *snake) {
    switch (window->state) {
    case START:
        if (IsKeyPressed(KEY_ENTER)) window->state = PLAY;
        break;
    case PLAY:
        if (IsKeyPressed(KEY_LEFT)) turn_snake(snake, LEFT);
        if (IsKeyPressed(KEY_RIGHT)) turn_snake(snake, RIGHT);
        if (IsKeyPressed(KEY_UP)) turn_snake(snake, UP);
        if (IsKeyPressed(KEY_DOWN)) turn_snake(snake, DOWN);
        break;
    case GAME_OVER:
        if (IsKeyPressed(KEY_ENTER)) window->state = PLAY;
        break;
    default:
        break;
    }
}
