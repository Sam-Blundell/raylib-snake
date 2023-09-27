#include "raylib.h"
#include "window.h"
#include "snake.h"

void process_input(struct game_window *window, struct snake *snake) {
    switch (window->state) {
    case START_MENU:
        if (IsKeyPressed(KEY_ENTER)) window->state = PLAY;
        if (IsKeyPressed(KEY_M)) window->state = SETTINGS_MENU;
        break;
    case SETTINGS_MENU:
        if (IsKeyPressed(KEY_M)) window->state = START_MENU;
        break;
    case PLAY:
        if (IsKeyPressed(KEY_LEFT)) turn_snake(snake, LEFT);
        if (IsKeyPressed(KEY_RIGHT)) turn_snake(snake, RIGHT);
        if (IsKeyPressed(KEY_UP)) turn_snake(snake, UP);
        if (IsKeyPressed(KEY_DOWN)) turn_snake(snake, DOWN);
        if (IsKeyPressed(KEY_P)) window->state = PAUSE;
        break;
    case PAUSE:
        if (IsKeyPressed(KEY_P)) window->state = PLAY;
        if (IsKeyPressed(KEY_S)) reset_game(window, snake, START_MENU);
        if (IsKeyPressed(KEY_R)) reset_game(window, snake, PLAY);
        break;
    case GAME_OVER:
        if (IsKeyPressed(KEY_R)) reset_game(window, snake, PLAY);
        if (IsKeyPressed(KEY_S)) reset_game(window, snake, START_MENU);
        break;
    default:
        break;
    }
}
