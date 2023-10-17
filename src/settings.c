#include <stdbool.h>
#include "settings.h"

struct settings init_settings() {
    struct settings settings = {
        .borderlessMode = true,
        .sound = true,
        .currentSetting = BORDERLESS_MODE,
    };
    return settings;
}

int selector_position(struct settings settings) {
    return 220 + ((int)settings.currentSetting * 60);
}

void toggle_setting(struct settings *settings) {
    switch (settings->currentSetting) {
    case BORDERLESS_MODE:
        settings->borderlessMode = !settings->borderlessMode;
        break;
    case SOUND:
        settings->sound = !settings->sound;
        break;
    case TEST_OPTION:
        break;
    default:
        break;
    }
}
