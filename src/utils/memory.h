#ifndef __UTILS_MEMORY_H__
    #define __UTILS_MEMORY_H__

    #include <stddef.h>
    #include "types.h"

/*
**          MEMORY ALLOCATION FUNCTIONS
** This is memory allocation and management public api
** this is the only file that you must includes if you want
** memory functions.
*/

void *malloc(size_t size);
void *memcpy(void *dst, const void *src, u32 n);

#endif