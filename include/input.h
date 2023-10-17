#ifndef INPUT_H
#define INPUT_H

#include "window.h"
#include "snake.h"

void input_start(struct game_window*);
void input_settings(struct game_window*);
void input_play(struct game_window*, struct snake*);
void input_pause(struct game_window*, struct snake*);
void input_gameover(struct game_window*, struct snake*);
void process_input(struct game_window*, struct snake*);

#endif // INPUT_H
