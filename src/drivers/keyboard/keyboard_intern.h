#ifndef __KEYBOARD_INTERN_H__
    #define __KEYBOARD_INTERN_H__

    #include "interrupts/isr.h"
    #include "drivers/screen.h"
    #include "shell/shell.h"
    #include "utils/string.h"
    #include "drivers/keyboard.h"

    #include <stddef.h>

    #define NB_LANG 2

enum Lang {
    US,
    FR
};

size_t curr_lang = US;
const char *accepted_lang[NB_LANG] = {
    "US", "FR"
};


#endif