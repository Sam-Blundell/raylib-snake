#include "window.h"
#include "raylib.h"

#define STARTING_UPDATE_RATE 0.2
#define MIN_UPDATE_RATE 0.06
#define SPEED_INTERVAL 5

struct game_window create_game_window(const char *title, int width, int height) {
    struct game_window window = {
        .title = title,
        .width = width,
        .height = height,
        .center = (Vector2){ width / 2.0f, height / 2.0f },
        .score = 0,
        .delta_t = 0,
        .update_rate = STARTING_UPDATE_RATE,
    };
    return window;
}

void increment_score(struct game_window *window) {
    window->score++;
    sprintf(window->score_string, "score: %d", window->score);
    if (window->score % SPEED_INTERVAL == 0 && window->update_rate > MIN_UPDATE_RATE) {
        window->update_rate -= 0.01;
    }
}

void game_over() {
    DrawText("Game Over", 400, 300, 20, RED);
}
