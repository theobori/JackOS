#include "memset.h"

/**
 * @brief memset function
 * 
 * @param dest: destination
 * @param c : char to fill
 * @param n : number of bytes to fill
 */
void memset(void *dest, u8 c, size_t n)
{
    char *d = (char *)dest;

    for (size_t i = 0; i < n; i++)
        d[i] = c;
}