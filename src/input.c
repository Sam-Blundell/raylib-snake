#include "raylib.h"
#include "window.h"
#include "snake.h"
#include "settings.h"

void input_start(struct game_window *window) {
    if (IsKeyPressed(KEY_ENTER)) window->state = PLAY;
    if (IsKeyPressed(KEY_M)) window->state = SETTINGS_MENU;
}

void input_settings(struct game_window *window, struct settings *settings) {
    if (IsKeyPressed(KEY_M)) window->state = START_MENU;
    if (IsKeyPressed(KEY_UP)) settings->currentSetting = (settings->currentSetting - 1 + TOTAL_SETTINGS) % TOTAL_SETTINGS;
    if (IsKeyPressed(KEY_DOWN)) settings->currentSetting = (settings->currentSetting + 1) % TOTAL_SETTINGS;
    if (IsKeyPressed(KEY_ENTER)) toggle_setting(settings);
}

void input_play(struct game_window *window, struct snake *snake) {
    if (IsKeyPressed(KEY_LEFT)) turn_snake(snake, LEFT);
    if (IsKeyPressed(KEY_RIGHT)) turn_snake(snake, RIGHT);
    if (IsKeyPressed(KEY_UP)) turn_snake(snake, UP);
    if (IsKeyPressed(KEY_DOWN)) turn_snake(snake, DOWN);
    if (IsKeyPressed(KEY_P)) window->state = PAUSE;
}

void input_pause(struct game_window *window, struct snake *snake) {
    if (IsKeyPressed(KEY_P)) window->state = PLAY;
    if (IsKeyPressed(KEY_S)) reset_game(window, snake, START_MENU);
    if (IsKeyPressed(KEY_R)) reset_game(window, snake, PLAY);
}

void input_gameover(struct game_window *window, struct snake *snake) {
    if (IsKeyPressed(KEY_R)) reset_game(window, snake, PLAY);
    if (IsKeyPressed(KEY_S)) reset_game(window, snake, START_MENU);
}

void process_input(struct game_window *window, struct snake *snake, struct settings *settings) {
    switch (window->state) {
    case START_MENU:
        input_start(window);
        break;
    case SETTINGS_MENU:
        input_settings(window, settings);
        break;
    case PLAY:
        input_play(window, snake);
        break;
    case PAUSE:
        input_pause(window, snake);
        break;
    case GAME_OVER:
        input_gameover(window, snake);
        break;
    default:
        break;
    }
}
