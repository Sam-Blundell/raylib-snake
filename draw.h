#ifndef DRAW_H
#define DRAW_H

#include "raylib.h"
#include "window.h"
#include "snake.h"
#include "pellet.h"

void draw_screen(struct game_window*, struct snake*, struct pellet*);

#endif // DRAW_H