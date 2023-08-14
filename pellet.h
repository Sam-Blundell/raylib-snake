#ifndef PELLET_H
#define PELLET_H

#include "raylib.h"
#include "window.h"

struct pellet {
    Vector2 position;
    int width;
};

struct pellet create_pellet(struct game_window);
Vector2 move_pellet(struct game_window);
void draw_pellet(struct pellet);

#endif // PELLET_H
