#include "memcpy.h"

/**
 * @brief memcpy function
 * 
 * @param dst : destination
 * @param src : source
 * @param n : number of bytes to copy
 * @return void* : destination
 */
void *memcpy(void *dst, const void *src, size_t n)
{
    char *ret = dst;
    char *p = dst;
    const char *q = src;
    while (n--)
        *p++ = *q++;
    return ret;
}