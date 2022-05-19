#include "trim.h"

static void r_trim(char *str, char *sep)
{
    const int len = strlen(str);

    for (int i = len - 1; i >= 0; i--) {
        if (in(str[i], sep))
            str[i] = 0;
        else
            break;
    }
}

static void l_trim(char *str, char *sep)
{
    while (in(*str, sep))
        str++;
}

void trim(char *str, char *sep)
{
    l_trim(str, sep);
    r_trim(str, sep);
}