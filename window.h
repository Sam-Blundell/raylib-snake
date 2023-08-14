#ifndef WINDOW_H
#define WINDOW_H

#include "raylib.h"

struct game_window {
    const char *title;
    int width;
    int height;
    Vector2 center;
    float delta_t;
};

struct game_window create_game_window(const char *title, int width, int height);

#endif // WINDOW_H
