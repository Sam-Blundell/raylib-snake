#ifndef DRAWUPDATE_H
#define DRAWUPDATE_H

#include "window.h"
#include "snake.h"
#include "pellet.h"
#include "settings.h"

void draw_input_update(struct game_window*, struct snake*, struct pellet*, struct settings*);
void web_loop(void* dataPtr);

#endif // DRAWUPDATE_H
