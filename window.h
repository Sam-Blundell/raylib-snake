#ifndef WINDOW_H
#define WINDOW_H

#include "raylib.h"
#include <stdio.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

enum game_state {
    START,
    PLAY,
    GAME_OVER,
};

struct game_window {
    const char *title;
    int width;
    int height;
    Vector2 center;
    int score;
    char score_string[11];
    float delta_t;
    float update_rate;
    enum game_state state;
};

struct game_window create_game_window(const char *title, int width, int height);
void increment_score(struct game_window *window);

#endif // WINDOW_H
