#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdbool.h>

enum setting {
    BORDERLESS_MODE,
    SOUND,
    TEST_OPTION,
    TOTAL_SETTINGS,
};

struct settings {
    bool borderlessMode;
    bool sound;
    enum setting currentSetting;
};

struct settings init_settings();

#endif // SETTINGS_H
