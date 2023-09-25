#include <stdio.h>
#include "raylib.h"
#include "window.h"
#include "snake.h"
#include "pellet.h"
#include "input.h"
#include "draw.h"
#include "update.h"

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT);
    SetTargetFPS(144);
    struct game_window window = create_game_window("Snake", WINDOW_WIDTH, WINDOW_HEIGHT);
    InitWindow(window.width, window.height, "Snake");
    struct snake snake = create_snake(window.center);
    struct pellet pellet = create_pellet(window, snake);

    while (!WindowShouldClose()) {
        draw_screen(&window, &snake, &pellet);
        process_input(&window, &snake);
        update_game(&window, &snake, &pellet);
    }

    CloseWindow();
    return 0;
}
