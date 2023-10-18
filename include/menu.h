#ifndef MENU_H
#define MENU_H

#define TITLE_FONT_SIZE 120
#define MENU_FONT_SIZE 40
#define SPACING 80

enum start_menu_options {
    START,
    SETTINGS,
    QUIT,
    TOTAL_START_MENU_OPTIONS,
};

struct menu {
    const char *title;
    const char **options;
    int numOptions;
    int currentOption;
};

extern struct menu start_menu;
extern struct menu settings_menu;
extern struct menu pause_menu;

#endif // MENU_H
