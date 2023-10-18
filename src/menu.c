#include "menu.h"

#ifdef __EMSCRIPTEN__
const char *start_menu_options[] = {
    "Start",
    "Settings",
};
#else
const char *start_menu_options[] = {
    "Start",
    "Settings",
    "Quit",
};
#endif

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
    .titleColour = WHITE,
    .titleFontSize = TITLE_FONT_SIZE,
    .startYPos = 100,
    .options = start_menu_options,
    .menuFontSize = MENU_FONT_SIZE,
    .numOptions = sizeof(start_menu_options) / sizeof(start_menu_options[0]),
    .currentOption = 0,
};

struct menu settings_menu = {
    .title = "Settings",
    .titleColour = WHITE,
    .titleFontSize = TITLE_FONT_SIZE,
    .startYPos = 100,
    .options = settings_menu_options,
    .menuFontSize = MENU_FONT_SIZE,
    .numOptions = sizeof(settings_menu_options) / sizeof(settings_menu_options[0]),
    .currentOption = 0,
};

struct menu pause_menu = {
    .title = "Paused",
    .titleColour = WHITE,
    .titleFontSize = TITLE_FONT_SIZE,
    .startYPos = 100,
    .options = pause_menu_options,
    .menuFontSize = MENU_FONT_SIZE,
    .numOptions = sizeof(pause_menu_options) / sizeof(pause_menu_options[0]),
    .currentOption = 0,
};

struct menu game_over_menu = {
    .title = "GAME OVER",
    .titleColour = RED,
    .titleFontSize = 80,
    .startYPos = 200,
    .options = gameover_menu_options,
    .menuFontSize = MENU_FONT_SIZE,
    .numOptions = sizeof(gameover_menu_options) / sizeof(gameover_menu_options[0]),
    .currentOption = 0,
};
