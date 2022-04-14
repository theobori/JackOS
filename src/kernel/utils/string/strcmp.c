#include "strcmp.h"

/**
 * @brief function that compares two strings
 * 
 * @param s1 : the first string
 * @param s2 : the second string
 * @return int : 1 if the strings are equal, 0 otherwise
 */
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