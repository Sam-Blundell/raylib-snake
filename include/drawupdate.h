#ifndef DRAWUPDATE_H
#define DRAWUPDATE_H

#include "window.h"
#include "snake.h"
#include "pellet.h"

void draw_input_update(struct game_window*, struct snake*, struct pellet*);
void web_loop(struct game_data*);

#endif // DRAWUPDATE_H
