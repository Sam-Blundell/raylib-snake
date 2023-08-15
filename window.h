#ifndef WINDOW_H
#define WINDOW_H

#include "raylib.h"
#include <stdio.h>

struct game_window {
    const char *title;
    int width;
    int height;
    Vector2 center;
    bool game_over;
    int score;
    char score_string[10];
    float delta_t;
    float update_rate;
};

struct game_window create_game_window(const char *title, int width, int height);
void increment_score(struct game_window *window);
void game_over();

#endif // WINDOW_H
