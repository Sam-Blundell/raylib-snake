#ifndef DRAW_H
#define DRAW_H

#include "window.h"
#include "snake.h"
#include "pellet.h"

Color darken_color(Color, float);
void draw_play(struct snake*, struct pellet*, struct game_window);
void draw_pause(struct game_window, struct snake, struct pellet);
void draw_gameover(struct game_window, struct snake, struct pellet);
void draw_screen(struct game_window, struct snake*, struct pellet*);

#endif // DRAW_H
