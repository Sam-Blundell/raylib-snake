#include "raylib.h"
#include "window.h"
#include "snake.h"
#include "pellet.h"
#include "settings.h"
#include "drawupdate.h"
#ifdef __EMSCRIPTEN__
    #include <emscripten.h>
#endif

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT);
    SetTargetFPS(144);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Snek");
    InitAudioDevice();
    struct game_window window = create_game_window("Snek", WINDOW_WIDTH, WINDOW_HEIGHT);
    struct snake snake = create_snake(window.center);
    struct pellet pellet = create_pellet(window, snake);
    struct settings settings = init_settings();

    #ifdef __EMSCRIPTEN__
        struct game_data data = {
            .window = &window,
            .snake = &snake,
            .pellet = &pellet,
            .settings = &settings,
        };

        emscripten_set_main_loop_arg(web_loop, &data, 0, 1);
    #else
        while (!WindowShouldClose()) {
            draw_input_update(&window, &snake, &pellet, &settings);
        }
    #endif

    CloseAudioDevice();
    CloseWindow();
    return 0;
}

// if the border is on we should also draw it which means we need to also
// make sure that the pellets don't spawn on the border
