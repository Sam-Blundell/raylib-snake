#ifndef SNAKE_H
#define SNAKE_H

#include "window.h"
#include "raylib.h"
#include "soundhandler.h"

#define MAX_SNAKE_LENGTH 256

extern const char LEFT;
extern const char RIGHT;
extern const char UP;
extern const char DOWN;

struct snake {
    Vector2 body[MAX_SNAKE_LENGTH];
    int length;
    int width;
    char direction;
    bool turning;
    struct snake_sounds sounds;
};

struct snake create_snake(Vector2);
void turn_snake(struct snake*, char);
void update_snake(struct snake*, struct game_window);
void draw_snake(struct snake);

#endif // SNAKE_H
