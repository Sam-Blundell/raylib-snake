#ifndef UPDATE_H
#define UPDATE_H

#include "window.h"
#include "snake.h"
#include "pellet.h"

void update_game(struct game_window*, struct snake*, struct pellet*, bool noBorder);

#endif // UPDATE_H
