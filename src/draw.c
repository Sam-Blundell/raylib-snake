#include "raylib.h"
#include "window.h"
#include "snake.h"
#include "pellet.h"
#include "draw.h"
#include "menu.h"

Color darken_color(Color color, float factor) {
    Color result;
    result.r = (unsigned char)(color.r * factor);
    result.g = (unsigned char)(color.g * factor);
    result.b = (unsigned char)(color.b * factor);
    result.a = color.a;
    return result;
}

int center_text(const char *title, int fontSize, int yPos, Color colour) {
    int xPos = (WINDOW_WIDTH / 2) - (MeasureText(title, fontSize) / 2);
    DrawText(title, xPos, yPos, fontSize, colour);
    return xPos;
}

void draw_options(struct game_window window, struct snake snake) {
    int yPos = 340;
    int xpos = 550;
    int opts[] = {(int)window.borderless_mode, (int)window.sound_enabled};

    for (int i = 0; i < 2; i++) {
        if (opts[i]) {
            DrawText("<on>", xpos, yPos, MENU_FONT_SIZE, WHITE);
        } else {
            DrawText("<off>", xpos, yPos, MENU_FONT_SIZE, WHITE);
        }
        yPos += SPACING;
    }
    DrawRectangleV((Vector2){xpos, yPos + 10}, (Vector2){60, 20}, game_colours[snake.colour]);
    DrawRectangleV((Vector2){xpos + 60, yPos + 10}, (Vector2){20, 20}, darken_color(game_colours[snake.colour], 0.7f));

}

void draw_menu(struct menu menu) {
    int yPos = menu.startYPos;
    int xPos = center_text(menu.title, menu.titleFontSize, yPos, menu.titleColour);
    yPos += SPACING;
    for (int i = 0; i < menu.numOptions; i++) {
        DrawText(menu.options[i], xPos, yPos + (i + 1) * SPACING, menu.menuFontSize, WHITE);
    }
    DrawText("->", xPos - 50, yPos + (menu.currentOption + 1) * SPACING, menu.menuFontSize, WHITE);
}

void draw_play(struct snake *snake, struct pellet *pellet, struct game_window window) {
    draw_pellet(*pellet);
    draw_snake(*snake);
    DrawText(window.score_string, 10, 10, 20, WHITE);
}

void draw_pause(struct game_window window, struct snake snake, struct pellet pellet) {
    draw_pellet(pellet);
    draw_snake(snake);
    draw_menu(pause_menu);
    DrawText(window.score_string, 10, 10, 20, WHITE);
}

void draw_gameover(struct game_window window, struct snake snake, struct pellet pellet) {
    draw_pellet(pellet);
    draw_snake(snake);
    draw_menu(game_over_menu);
    DrawText(window.score_string, 10, 10, 20, WHITE);
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
        draw_options(window, *snake);
        break;
    case PLAY:
        draw_play(snake, pellet, window);
        break;
    case PAUSE:
        draw_pause(window, *snake, *pellet);
        break;
    case GAME_OVER:
        draw_gameover(window, *snake, *pellet);
        break;
    default:
        break;
    }
    EndDrawing();
}
