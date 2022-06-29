#include "count.h"

size_t count(const char *str, char c)
{
    size_t nb_occurs = 0;
    for (size_t i = 0; str[i]; i++) {
        if (str[i] == c) {
            nb_occurs++;
        }
    }
    return (nb_occurs);
}