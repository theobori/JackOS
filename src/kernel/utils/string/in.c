#include "in.h"

/**
 * @brief basic function that checks if the char is in the string
 * 
 * @param c 
 * @param str 
 * @return int 
 */
int in(char c, const char *str)
{
    for (int i = 0; str[i]; i++) {
        if (c == str[i]) {
            return (1);
        }
    }
    return (0);
}