#include "raylib.h"
#include "pellet.h"
#include "snake.h"

Vector2 move_pellet(struct game_window window, struct snake snake) {
     Vector2 position = (Vector2){
        GetRandomValue(0, (window.width - 20) / 20) * 20,
        GetRandomValue(0, (window.height - 20) / 20) * 20,
    };

    for (int i = 0; i < snake.length; i++) {
        if (position.x == snake.body[i].x && position.y == snake.body[i].y) {
            position = move_pellet(window, snake);
        }
    }

    return position;
}

struct pellet create_pellet(struct game_window window, struct snake snake) {
    struct pellet pellet = {
        .width = 20,
        .position = move_pellet(window, snake),
    };
    return pellet;
}

void draw_pellet(struct pellet pellet) {
    DrawRectangleV(pellet.position, (Vector2){pellet.width, pellet.width}, WHITE);
}
