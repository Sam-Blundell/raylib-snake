#include "collisions.h"

void eat_pellet(struct snake *snake, struct pellet *pellet, struct game_window *window) {
    if (snake->body[0].x == pellet->position.x && snake->body[0].y == pellet->position.y) {
        snake->length++;
        pellet->position = move_pellet(*window, *snake);
        increment_score(window);
    }
}

void snake_collide(struct snake *snake, struct game_window *window) {
    Vector2 head = snake->body[0];
    for (int i = 1; i < snake->length; i++) {
        if (head.x == snake->body[i].x && head.y == snake->body[i].y) {
            window->state = GAME_OVER;
        }
    }
};