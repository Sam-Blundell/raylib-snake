#include "raylib.h"
#include "window.h"
#include "snake.h"
#include "pellet.h"
#include "drawupdate.h"
#ifdef __EMSCRIPTEN__
    #include <emscripten.h>
#endif

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT);
    SetTargetFPS(144);
    struct game_window window = create_game_window("Snek", WINDOW_WIDTH, WINDOW_HEIGHT);
    InitWindow(window.width, window.height, "Snek");
    struct snake snake = create_snake(window.center);
    struct pellet pellet = create_pellet(window, snake);

    #ifdef __EMSCRIPTEN__
        struct game_data data = {
            .window = &window,
            .snake = &snake,
            .pellet = &pellet,
        };

        emscripten_set_main_loop_arg(web_loop, &data, 0, 1);
    #else
        while (!WindowShouldClose()) {
            draw_input_update(&window, &snake, &pellet);
        }
    #endif

    CloseWindow();
    return 0;
}

// Adding a settings menu with the ability to turn on and off the border.
// if the border is on we should also draw it which means we need to also
// make sure that the pellets don't spawn on the border