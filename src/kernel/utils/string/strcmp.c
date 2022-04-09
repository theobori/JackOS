#include "strcmp.h"

int strcmp(const char *s1, const char *s2)
{
    int i = 0;
    for (; s1[i]; i++) {
        if (s1[i] != s2[i])
            return (0);
    }
    if (s2[i] != 0)
        return (0);
    return (1);
}