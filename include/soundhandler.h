#ifndef SOUND_HANDLER_H
#define SOUND_HANDLER_H

#include "raylib.h"

struct snake_sounds {
    Sound eat;
    Sound die;
};

struct snake_sounds load_snake_sounds();
void unload_snake_sounds(struct snake_sounds);

#endif // SOUND_HANDLER_H
