#include "raylib.h"
#include "window.h"
#include "snake.h"
#include "draw.h"
#include "menu.h"

void input_start(struct game_window *window) {
    if (IsKeyPressed(KEY_UP)) start_menu.currentOption = (start_menu.currentOption - 1 + start_menu.numOptions) % start_menu.numOptions;
    if (IsKeyPressed(KEY_DOWN)) start_menu.currentOption = (start_menu.currentOption + 1) % start_menu.numOptions;
    if (IsKeyPressed(KEY_ENTER)) {
        switch (start_menu.currentOption) {
            case START:
                window->state = PLAY;
                break;
            case SETTINGS:
                window->state = SETTINGS_MENU;
                break;
            case QUIT:
                window->quit = true;
                break;
            default:
                break;
        }
    }
}

void input_settings(struct game_window *window) {
    if (IsKeyPressed(KEY_UP)) settings_menu.currentOption = (settings_menu.currentOption - 1 + settings_menu.numOptions) % settings_menu.numOptions;
    if (IsKeyPressed(KEY_DOWN)) settings_menu.currentOption = (settings_menu.currentOption + 1) % settings_menu.numOptions;
    if (IsKeyPressed(KEY_ENTER)) {
        switch (settings_menu.currentOption) {
            case 0:
                window->state = START_MENU;
                break;
            case 1:
                window->borderless_mode = !window->borderless_mode;
                break;
            case 2:
                window->sound_enabled = !window->sound_enabled;
                break;
            case 3:
                // TODO: colour changing functionality.
                break;
            default:
                break;
        }
    }
}

void input_play(struct game_window *window, struct snake *snake) {
    if (IsKeyPressed(KEY_LEFT)) turn_snake(snake, LEFT);
    if (IsKeyPressed(KEY_RIGHT)) turn_snake(snake, RIGHT);
    if (IsKeyPressed(KEY_UP)) turn_snake(snake, UP);
    if (IsKeyPressed(KEY_DOWN)) turn_snake(snake, DOWN);
    if (IsKeyPressed(KEY_ENTER)) window->state = PAUSE;
}

void input_pause(struct game_window *window, struct snake *snake) {
    if (IsKeyPressed(KEY_UP)) pause_menu.currentOption = (pause_menu.currentOption - 1 + pause_menu.numOptions) % pause_menu.numOptions;
    if (IsKeyPressed(KEY_DOWN)) pause_menu.currentOption = (pause_menu.currentOption + 1) % pause_menu.numOptions;
    if (IsKeyPressed(KEY_ENTER)) {
        switch (pause_menu.currentOption) {
            case 0:
                window->state = PLAY;
                break;
            case 1:
                reset_game(window, snake, START_MENU);
                break;
            case 2:
                reset_game(window, snake, PLAY);
                break;
            default:
                break;
        }
    }
}

void input_gameover(struct game_window *window, struct snake *snake) {
    if (IsKeyPressed(KEY_ENTER)) reset_game(window, snake, START_MENU);
}

void process_input(struct game_window *window, struct snake *snake) {
    switch (window->state) {
    case START_MENU:
        input_start(window);
        break;
    case SETTINGS_MENU:
        input_settings(window);
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
