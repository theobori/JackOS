#ifndef __TTY_INTERN_H__
    #define __TTY_INTERN_H__
    
    #include "types.h"
    #include "GUI/GUI.h"

typedef struct tty_intern_s {
    size_t cx;
    size_t cy;
    size_t buff_w;
    size_t buff_h;
    char prompt[100];
    char buffer[37][100];
    int prompt_index[37];
    int test;
    char test_cmd[2000];
} tty_intern_t;

tty_intern_t this;

#endif