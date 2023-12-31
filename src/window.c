#include <stdio.h>
#include <string.h>
#include "window.h"
#include "snake.h"

const float STARTING_UPDATE_RATE = 0.2f;
const float MIN_UPDATE_RATE = 0.06f;
const int SPEED_INTERVAL = 5;

Color game_colours[] = {
    WHITE,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    PURPLE,
    PINK,
    BROWN,
    LIGHTGRAY,
    GRAY,
    DARKGRAY,
};

struct game_window create_game_window(const char *title, int width, int height) {
    struct game_window window = {
        .title = title,
        .width = width,
        .height = height,
        .center = (Vector2){ width / 2.0f, height / 2.0f },
        .score = 0,
        .delta_t = 0,
        .update_rate = STARTING_UPDATE_RATE,
        .state = START_MENU,
        .borderless_mode = true,
        .sound_enabled = true,
        .quit = false,
    };
    strncpy(window.score_string, "score: 0", SCORE_TEXT_LENGTH);
    return window;
}

void increment_score(struct game_window *window) {
    window->score++;
    sprintf(window->score_string, "score: %d", window->score);
    if (window->score % SPEED_INTERVAL == 0 && window->update_rate > MIN_UPDATE_RATE) {
        window->update_rate -= 0.01f;
    }
}

void reset_game(struct game_window *window, struct snake *snake, enum game_state newState) {
    snake->length = 1;
    snake->direction = RIGHT;
    snake->turning = false;
    snake->body[0] = window->center;
    window->score = 0;
    strncpy(window->score_string, "score: 0", SCORE_TEXT_LENGTH);
    window->update_rate = STARTING_UPDATE_RATE;
    window->state = newState;
}
