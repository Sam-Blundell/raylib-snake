#include "raylib.h"
#include "window.h"
#include "snake.h"
#include "pellet.h"
#include "drawupdate.h"
#include "soundhandler.h"
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

    #ifdef __EMSCRIPTEN__
        struct game_data data = {
            .window = &window,
            .snake = &snake,
            .pellet = &pellet,
        };

        emscripten_set_main_loop_arg(web_loop, &data, 0, 1);
    #else
        while (!WindowShouldClose() && !window.quit) {
            draw_input_update(&window, &snake, &pellet);
        }
    #endif

    unload_snake_sounds(snake.sounds);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
