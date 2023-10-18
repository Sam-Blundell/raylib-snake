#ifndef WINDOW_H
#define WINDOW_H

#include "raylib.h"
#include <stdbool.h>

#define SCORE_TEXT_LENGTH 11

static const int WINDOW_WIDTH = 800;
static const int WINDOW_HEIGHT = 600;


extern Color game_colours[];

enum game_state {
    START_MENU,
    SETTINGS_MENU,
    PLAY,
    PAUSE,
    GAME_OVER,
};

struct game_window {
    const char *title;
    int width;
    int height;
    Vector2 center;
    int score;
    char score_string[SCORE_TEXT_LENGTH];
    float delta_t;
    float update_rate;
    enum game_state state;
    bool borderless_mode;
    bool sound_enabled;
    bool quit;
};

struct game_data {
    struct game_window *window;
    struct snake *snake;
    struct pellet *pellet;
};

//forward definition of snake struct
struct snake;

struct game_window create_game_window(const char*, int, int);
void increment_score(struct game_window*);
void reset_game(struct game_window*, struct snake*, enum game_state);

#endif // WINDOW_H
