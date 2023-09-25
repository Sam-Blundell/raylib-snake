#include "window.h"
#include "raylib.h"

const float STARTING_UPDATE_RATE = 0.2f;
const float MIN_UPDATE_RATE = 0.06f;
const int SPEED_INTERVAL = 5;

struct game_window create_game_window(const char *title, int width, int height) {
    struct game_window window = {
        .title = title,
        .width = width,
        .height = height,
        .center = (Vector2){ width / 2.0f, height / 2.0f },
        .score = 0,
        .score_string = "score: 0",
        .delta_t = 0,
        .update_rate = STARTING_UPDATE_RATE,
        .state = START,
    };
    return window;
}

void increment_score(struct game_window *window) {
    window->score++;
    sprintf(window->score_string, "score: %d", window->score);
    if (window->score % SPEED_INTERVAL == 0 && window->update_rate > MIN_UPDATE_RATE) {
        window->update_rate -= 0.01f;
    }
}
