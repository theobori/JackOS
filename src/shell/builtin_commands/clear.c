#include "clear.h"

void clear(__attribute__((unused))char **args)
{
    kclear_screen(SET_COLOR(WHITE, BLACK));
    shell.y = 0;
}