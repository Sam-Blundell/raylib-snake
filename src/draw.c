#include "raylib.h"
#include "window.h"
#include "snake.h"
#include "pellet.h"
#include "settings.h"

void draw_start() {
    DrawText("SNEK", 340, 200, 40, WHITE);
    DrawText("Press Enter to Start", 260, 300, 25, WHITE);
    DrawText("Press M for Settings", 260, 350, 25, WHITE);
}

void draw_settings(struct settings settings) {
    DrawText("Settings", 320, 100, 40, WHITE);
    DrawText("Press M to Return to Start Menu", 200, 160, 25, WHITE);
    DrawText(">", 120, selector_position(settings), 25, WHITE);
    DrawText(TextFormat("Borderless Mode: %s", settings.borderlessMode ? "ON" : "OFF"), 150, 220, 25, WHITE);
    DrawText(TextFormat("Sound: %s", settings.sound ? "ON" : "OFF"), 150, 280, 25, WHITE);
    // DrawText("SNEK Colour: < WHITE >", 150, 340, 25, WHITE);
    DrawText(TextFormat("SNEK Colour: < %s >", "WHITE"), 150, 340, 25, WHITE);
}

void draw_play(struct snake *snake, struct pellet *pellet, struct game_window window) {
    draw_pellet(*pellet);
    draw_snake(*snake);
    DrawText(window.score_string, 10, 10, 20, WHITE);
}

void draw_pause(struct snake snake, struct pellet pellet) {
    draw_pellet(pellet);
    draw_snake(snake);
    DrawText("Pause", 340, 200, 40, WHITE);
    DrawText("Press P to un-pause", 260, 300, 25, WHITE);
    DrawText("Press R To Restart", 255, 350, 25, WHITE);
    DrawText("Press S To Return To Start Menu", 255, 400, 25, WHITE);
}

void draw_gameover(struct snake snake, struct pellet pellet) {
    draw_pellet(pellet);
    draw_snake(snake);
    DrawText("Game Over", 290, 200, 40, RED);
    DrawText("Press R To Restart", 255, 300, 25, WHITE);
    DrawText("Press S To Return To Start Menu", 255, 350, 25, WHITE);
}

void draw_screen(struct game_window window, struct snake *snake, struct pellet *pellet, struct settings settings) {
    BeginDrawing();
    ClearBackground(BLACK);
    switch (window.state) {
    case START_MENU:
        draw_start();
        break;
    case SETTINGS_MENU:
        draw_settings(settings);
        break;
    case PLAY:
        draw_play(snake, pellet, window);
        break;
    case PAUSE:
        draw_pause(*snake, *pellet);
        break;
    case GAME_OVER:
        draw_gameover(*snake, *pellet);
        break;
    default:
        break;
    }
    EndDrawing();
}
