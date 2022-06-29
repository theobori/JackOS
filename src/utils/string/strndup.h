#ifndef __STRNDUP_H__
    #define __STRNDUP_H__

    #include "types.h"
    #include "utils/memory.h"
    #include "strncpy.h"
    #include "strlen.h"

char *strndup(const char *str, const size_t n);

#endif