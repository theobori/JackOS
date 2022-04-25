#include "strncpy.h"

/**
 * @brief function that copy n elems from src to dest
 * 
 * @param dest : destination
 * @param src : source
 * @param n : number of elems to copy
 */
void strncpy(char *dest, const char *src, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    dest[n] = '\0';
}