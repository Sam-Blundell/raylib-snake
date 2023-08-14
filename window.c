#include "window.h"
#include "raylib.h"

struct game_window create_game_window(const char *title, int width, int height) {
    struct game_window window = {
        .title = title,
        .width = width,
        .height = height,
        .center = (Vector2){ width / 2.0f, height / 2.0f },
        .delta_t = 0,
    };
    return window;
}
