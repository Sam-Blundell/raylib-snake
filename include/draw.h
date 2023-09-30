#ifndef DRAW_H
#define DRAW_H

#include "window.h"
#include "snake.h"
#include "pellet.h"
#include "settings.h"

void draw_start();
void draw_settings(struct settings);
void draw_play(struct snake*, struct pellet*, struct game_window);
void draw_pause(struct snake, struct pellet);
void draw_gameover(struct snake, struct pellet);
void draw_screen(struct game_window, struct snake*, struct pellet*, struct settings);

#endif // DRAW_H
