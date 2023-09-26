#include "draw.h"
#include "input.h"
#include "update.h"
#include "window.h"
#include "snake.h"
#include "pellet.h"

void draw_input_update(struct game_window *window, struct snake *snake, struct pellet *pellet) {
    draw_screen(*window, snake, pellet);
    process_input(window, snake);
    update_game(window, snake, pellet);
}

void web_loop(struct game_data *data) {
    draw_input_update(data->window, data->snake, data->pellet);
}
