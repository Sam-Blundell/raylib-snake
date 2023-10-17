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
