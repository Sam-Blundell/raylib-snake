#include "raylib.h"
#include "window.h"
#include "snake.h"
#include "pellet.h"

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
}

void border_collide(struct snake *snake, struct game_window *window) {
    Vector2 head = snake->body[0];
    if (head.x < 0 || head.x > window->width || head.y < 0 || head.y > window->height) {
        window->state = GAME_OVER;
    }
}
