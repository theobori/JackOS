#include "man.h"

int man_command(char **args)
{
    if (!args[1]) {
        return (1);
    }
    char *names[] = {
        "ping",
        "pwd",
        "cat",
        "man",
        "ls",
        "mkdir",
        "cd",
        "echo",
        "clear",
        NULL
    };
    char *txts[] = {
        #include "man/ping.txt"
        ,
        #include "man/pwd.txt"
        ,
        #include "man/cat.txt"
        ,
        #include "man/man.txt"
        ,
        #include "man/ls.txt"
        ,
        #include "man/mkdir.txt"
        ,
        #include "man/cd.txt"
        ,
        #include "man/echo.txt"
        ,
        #include "man/clear.txt"
        ,
        NULL
    };
    tty_newline(0, 0);
    size_t command_index = 0;
    for (; names[command_index]; command_index++) {
        if (strcmp(names[command_index], args[1])) {
            break;
        }
    }
    for (size_t i = 0; txts[command_index][i]; i++) {
        if (txts[command_index][i] == '\n') {
            tty_newline(0, 0);
        } else {
            tty_add_buff(txts[command_index][i]);
        }
    }
    return (0);
}