#include "soundhandler.h"
#include "raylib.h"

struct snake_sounds load_snake_sounds() {
    struct snake_sounds sounds = {
        .eat = LoadSound("resources/eat.wav"),
        .die = LoadSound("resources/die.wav"),
    };

    return sounds;
}

void unload_snake_sounds(struct snake_sounds sounds) {
    UnloadSound(sounds.eat);
    UnloadSound(sounds.die);
}
