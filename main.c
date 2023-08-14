#include <stdio.h>
#include "raylib.h"
#include "window.h"
#include "snake.h"
#include "pellet.h"

int main() {
    struct game_window window = create_game_window("Snake", 800, 600);
    struct snake snake = create_snake(window.center);
    struct pellet pellet = create_pellet(window);
    InitWindow(window.width, window.height, "Snake");

    while (!WindowShouldClose()) {
        window.delta_t += GetFrameTime();
        BeginDrawing();
        ClearBackground(BLACK);
        draw_snake(snake);
        draw_pellet(pellet);
        EndDrawing();
        turn_snake(&snake);
        if (window.delta_t > 0.2) {
            window.delta_t = 0;
            update_snake(&snake);
        };
    }

    CloseWindow();
    return 0;
}
