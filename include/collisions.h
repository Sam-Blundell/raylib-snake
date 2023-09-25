#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "snake.h"
#include "pellet.h"
#include "window.h"

void eat_pellet(struct snake*, struct pellet*, struct game_window*);
void snake_collide(struct snake*, struct game_window*);

#endif // COLLISIONS_H
