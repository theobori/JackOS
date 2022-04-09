#include "strcpy.h"

/**
 * @brief function that copy a string into another
 * 
 * @param dest : the destination string
 * @param src : the source string
 */
void strcpy(char *dest, const char *src)
{
    int i = 0;
    for (; src[i]; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}