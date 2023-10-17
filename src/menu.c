#include "menu.h"

const char *start_menu_options[] = {
    "Start",
    "Settings",
    "Quit",
};

const char *settings_menu_options[] = {
    "Borderless Mode",
    "Sound",
    "Snek Colour",
};

struct menu start_menu = {
    .title = "SNEK",
    .options = start_menu_options,
    .numOptions = sizeof(start_menu_options) / sizeof(start_menu_options[0]),
    .currentOption = 0,
};
