#include "raylib.h"
#include "window.h"
#include "snake.h"
#include "pellet.h"
#include "collisions.h"

void update_game(struct game_window* window, struct snake* snake, struct pellet* pellet) {
    window->delta_t += GetFrameTime();
    switch (window->state) {
        case START_MENU:
            break;
        case SETTINGS_MENU:
            break;
        case PLAY:
            if (window->delta_t > window->update_rate) {
                eat_pellet(snake, pellet, window);
                window->delta_t = 0;
                update_snake(snake, *window);
                snake_collide(snake, window);
                border_collide(snake, window);
            }
            break;
        case PAUSE:
            break;
        case GAME_OVER:
            break;
        default:
            break;
    }
}
