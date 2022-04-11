#include "help.h"

static void display_default()
{
    kprint_at("HELP", 0, ++shell.y, SET_COLOR(WHITE, BLACK));
    kprint_at("Command list :", 0, ++shell.y, SET_COLOR(WHITE, BLACK));
    kprint_at("    - help", 0, ++shell.y, SET_COLOR(WHITE, BLACK));
    kprint_at("    - setxkbmap", 0, ++shell.y, SET_COLOR(WHITE, BLACK));
    kprint_at("to have information about a command, type help <command>", 0, ++shell.y, SET_COLOR(WHITE, BLACK));
}

static void display_command(size_t command_index)
{
    for (size_t i = 0; commands_help[command_index][i] != NULL; i++) {
        kprint_at(commands_help[command_index][i], 0, ++shell.y, SET_COLOR(WHITE, BLACK));
    }
}

void help(char **args)
{
    const char *command_name[] = {
        "setxkbmap",
        "help",
        "clear",
        NULL
    };
    for (size_t i = 0; command_name[i] != NULL; i++) {
        if (strcmp(command_name[i], args[0])) {
            display_command(i);
            return;
        }
    }
    display_default();
}