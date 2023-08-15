#include "raylib.h"
#include "pellet.h"

Vector2 move_pellet(struct game_window window) {
    return (Vector2){
        // random multiple of 20 between 0 and window limits
        GetRandomValue(0, (window.width - 20) / 20) * 20,
        GetRandomValue(0, (window.height - 20) / 20) * 20,
    };
}

struct pellet create_pellet(struct game_window window) {
    struct pellet pellet = {
        .width = 20,
    };
    pellet.position = move_pellet(window);
    return pellet;
}

void draw_pellet(struct pellet pellet) {
    DrawRectangleV(pellet.position, (Vector2){pellet.width, pellet.width}, WHITE);
}
