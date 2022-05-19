#include "strdup.h"

/**
 * @brief Function that duplicate a string
 * 
 * @param str : the string to duplicate
 * @return char* : the duplicated string
 */
char *strdup(const char *str)
{
    char *new_str;
    size_t len = strlen(str);

    new_str = malloc(sizeof(char) * (len + 1));
    if (new_str == NULL)
        return (NULL);
    new_str[len] = '\0';
    strcpy(new_str, str);
    return (new_str);
}