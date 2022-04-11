#ifndef __HELP_H__
    #define __HELP_H__

    #include "drivers/screen.h"
    #include "../shell_intern.h"

const char **commands_help[] = {
    (const char *[]){
        "setxkbmap :",
        "- USAGE:",
        "    setxkbmap [layout]",
        "",
        "- DESCRIPTION:",
        "    Set the keyboard layout to the specified layout.",
        "",
        "- LAYOUTS",
        "    - US",
        "    - FR",
        NULL
    },
    (const char *[]){
        "help :",
        "- USAGE:",
        "    help //Display basic help",
        "    help [command]",
        "",
        "- DESCRIPTION:",
        "    Display help about a command.",
        NULL
    },
    (const char *[]){
        "clear :",
        "- USAGE:",
        "    clear",
        "",
        "- DESCRIPTION:",
        "    Clear the screen.",
        NULL
    },
    NULL
};

#endif