#include "raylib.h"
#include "window.h"
#include "snake.h"
#include "pellet.h"

void draw_screen(struct game_window window, struct snake *snake, struct pellet *pellet) {
    BeginDrawing();
    ClearBackground(BLACK);
    switch (window.state) {
    case START:
        DrawText("SNEK", 340, 200, 40, WHITE);
        DrawText("Press Enter to Start", 260, 300, 25, WHITE);
        break;
    case PLAY:
        draw_pellet(*pellet);
        draw_snake(*snake);
        DrawText(window.score_string, 10, 10, 20, WHITE);
        break;
    case GAME_OVER:
        DrawText("Game Over", 290, 200, 40, RED);
        DrawText("Press R To Play Again", 255, 300, 25, WHITE);
        DrawText(window.score_string, 10, 10, 20, WHITE);
        break;
    default:
        break;
    }
    EndDrawing();
}
