#include <stdio.h>
#include "raylib.h"
#include "window.h"
#include "snake.h"
#include "pellet.h"
#include "collisions.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT);
    SetTargetFPS(144);
    struct game_window window = create_game_window("Snake", WINDOW_WIDTH, WINDOW_HEIGHT);
    InitWindow(window.width, window.height, "Snake");
    struct snake snake = create_snake(window.center);
    struct pellet pellet = create_pellet(window);

    while (!WindowShouldClose()) {
        window.delta_t += GetFrameTime();
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText(window.score_string, 10, 10, 20, WHITE);
        draw_pellet(pellet);
        draw_snake(snake);
        EndDrawing();
        turn_snake(&snake);
        if (window.delta_t > window.update_rate && !window.game_over) {
            eat_pellet(&snake, &pellet, &window);
            window.delta_t = 0;
            update_snake(&snake, window);
            snake_collide(&snake, &window);
        };
        if (window.game_over) {
            game_over();
        }
    }

    CloseWindow();
    return 0;
}

// TODO:
// Collect all draw functions and update logic into one module
// figure out vsync
// Pellets shouldn't be able to spawn on top of the snake body
// Start screen
