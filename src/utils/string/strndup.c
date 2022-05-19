#include "strndup.h"

/**
 * @brief function that duplicate n char of a string
 * 
 * @param str : the string to duplicate
 * @param n : the nb of char to duplicate
 * @return char* : the duplicated string
 */
char *strndup(const char *str, size_t n)
{
    char *res = malloc(sizeof(char) * (n + 1));
    memset(res, 0, n + 1);

    for (size_t i = 0; i < n && str[i]; i++) {
        res[i] = str[i];
    }
    return (res);
}