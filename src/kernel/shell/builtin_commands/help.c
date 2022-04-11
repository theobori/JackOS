#include "help.h"

void help(__attribute__((unused))char **args)
{
    kprint_at("HELP", 0, ++shell.y, SET_COLOR(WHITE, BLACK));
    kprint_at("Command list :", 0, ++shell.y, SET_COLOR(WHITE, BLACK));
    kprint_at("    - help", 0, ++shell.y, SET_COLOR(WHITE, BLACK));
    kprint_at("    - setxkbmap", 0, ++shell.y, SET_COLOR(WHITE, BLACK));
    kprint_at("to have information about a command, type help <command>", 0, ++shell.y, SET_COLOR(WHITE, BLACK));
}