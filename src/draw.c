#include "raylib.h"
#include "window.h"
#include "snake.h"
#include "pellet.h"

void draw_screen(struct game_window window, struct snake *snake, struct pellet *pellet) {
    BeginDrawing();
    ClearBackground(BLACK);
    switch (window.state) {
    case START:
        DrawText("Press Enter to Start", 300, 300, 20, RED);
        break;
    case PLAY:
        draw_pellet(*pellet);
        draw_snake(*snake);
        DrawText(window.score_string, 10, 10, 20, WHITE);
        break;
    case GAME_OVER:
        DrawText("Game Over", 350, 300, 20, RED);
        DrawText(window.score_string, 10, 10, 20, WHITE);
        break;
    default:
        break;
    }
    EndDrawing();
}
