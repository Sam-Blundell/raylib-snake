#include "menu.h"

const char *start_menu_options[] = {
    "Start",
    "Settings",
    "Quit",
};

const char *settings_menu_options[] = {
    "Back",
    "Borderless Mode",
    "Sound",
    "Snek Colour",
};

const char *pause_menu_options[] = {
    "Resume",
    "Start Menu",
    "Restart",
};

const char *gameover_menu_options[] = {
    "Press Enter",
};

struct menu start_menu = {
    .title = "SNEK",
    .options = start_menu_options,
    .numOptions = sizeof(start_menu_options) / sizeof(start_menu_options[0]),
    .currentOption = 0,
};

struct menu settings_menu = {
    .title = "Settings",
    .options = settings_menu_options,
    .numOptions = sizeof(settings_menu_options) / sizeof(settings_menu_options[0]),
    .currentOption = 0,
};

struct menu pause_menu = {
    .title = "Paused",
    .options = pause_menu_options,
    .numOptions = sizeof(pause_menu_options) / sizeof(pause_menu_options[0]),
    .currentOption = 0,
};

struct menu game_over_menu = {
    .title = "GAME OVER",
    .options = gameover_menu_options,
    .numOptions = sizeof(gameover_menu_options) / sizeof(gameover_menu_options[0]),
    .currentOption = 0,
};
