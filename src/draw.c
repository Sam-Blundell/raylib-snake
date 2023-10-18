#include "raylib.h"
#include "window.h"
#include "snake.h"
#include "pellet.h"
#include "draw.h"
#include "menu.h"

int center_text(const char *title, int fontSize, int yPos) {
    int xPos = (WINDOW_WIDTH / 2) - (MeasureText(title, fontSize) / 2);
    DrawText(title, xPos, yPos, fontSize, WHITE);
    return xPos;
}

// Idea for showing the options in a menu:
// Have a menu with a blank title and if the title is blank
// the xpos value is shifted to the right by a certain amount.
// This way the options can be shown in a column.

void draw_menu(struct menu menu) {
    int yPos = 100;
    int xPos = center_text(menu.title, TITLE_FONT_SIZE, yPos);
    yPos += SPACING;
    for (int i = 0; i < menu.numOptions; i++) {
        DrawText(menu.options[i], xPos, yPos + (i + 1) * SPACING, MENU_FONT_SIZE, WHITE);
    }
    DrawText("->", xPos - 50, yPos + (menu.currentOption + 1) * SPACING, MENU_FONT_SIZE, WHITE);
}

void draw_play(struct snake *snake, struct pellet *pellet, struct game_window window) {
    draw_pellet(*pellet);
    draw_snake(*snake);
    DrawText(window.score_string, 10, 10, 20, WHITE);
}

void draw_pause(struct snake snake, struct pellet pellet) {
    draw_pellet(pellet);
    draw_snake(snake);
    draw_menu(pause_menu);
}

void draw_gameover(struct snake snake, struct pellet pellet) {
    draw_pellet(pellet);
    draw_snake(snake);
    DrawText("Game Over", 290, 200, 40, RED);
    DrawText("Press R To Restart", 255, 300, 25, WHITE);
    DrawText("Press S To Return To Start Menu", 255, 350, 25, WHITE);
}

void draw_screen(struct game_window window, struct snake *snake, struct pellet *pellet) {
    BeginDrawing();
    ClearBackground(BLACK);
    switch (window.state) {
    case START_MENU:
        draw_menu(start_menu);
        break;
    case SETTINGS_MENU:
        draw_menu(settings_menu);
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
