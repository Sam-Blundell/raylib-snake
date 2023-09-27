#include "raylib.h"
#include "window.h"
#include "snake.h"
#include "pellet.h"

void draw_screen(struct game_window window, struct snake *snake, struct pellet *pellet) {
    BeginDrawing();
    ClearBackground(BLACK);
    switch (window.state) {
    case START_MENU:
        DrawText("SNEK", 340, 200, 40, WHITE);
        DrawText("Press Enter to Start", 260, 300, 25, WHITE);
        DrawText("Press M for Settings", 260, 350, 25, WHITE);
        break;
    case SETTINGS_MENU:
        DrawText("Menu", 340, 200, 40, WHITE);
        DrawText("Press M to Return to Start Menu", 260, 300, 25, WHITE);
        break;
    case PLAY:
        draw_pellet(*pellet);
        draw_snake(*snake);
        DrawText(window.score_string, 10, 10, 20, WHITE);
        break;
    case PAUSE:
        DrawText("Pause", 340, 200, 40, WHITE);
        DrawText("Press P to un-pause", 260, 300, 25, WHITE);
        DrawText("Press R To Restart", 255, 350, 25, WHITE);
        DrawText("Press S To Return To Start Menu", 255, 400, 25, WHITE);
        break;
    case GAME_OVER:
        DrawText("Game Over", 290, 200, 40, RED);
        DrawText("Press R To Restart", 255, 300, 25, WHITE);
        DrawText("Press S To Return To Start Menu", 255, 350, 25, WHITE);
        DrawText(window.score_string, 10, 10, 20, WHITE);
        break;
    default:
        break;
    }
    EndDrawing();
}
