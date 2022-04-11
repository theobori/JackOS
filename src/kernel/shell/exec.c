#include "exec.h"

/**
 * @brief function that must execute all commands that the user input in the shell
 * 
 * @param cmd : the command to be executed
 */
void exec(const char *cmd)
{
    char **args = split(cmd, " ");
    char *cmd_name = args[0];
    char *command_name[] = {
        "setxkbmap",
        "help",
        NULL
    };
    void (*command_functions[])(char **) = {
        &setxkbmap,
        &help,
        NULL
    };
    int cmd_found = 0;

    args++;
    for (size_t i = 0; command_name[i] != NULL; i++) {
        if (strcmp(command_name[i], cmd_name)) {
            command_functions[i](args);
            cmd_found = 1;
            break;
        }
    }
    if (!cmd_found) {
        kprint_at(UNKNOWN_CMD, 0, ++shell.y, SET_COLOR(WHITE, BLACK));
    } else {
        kprint_at(COMMAND_EXECUTED, 0, ++shell.y, SET_COLOR(WHITE, BLACK));
    }
}