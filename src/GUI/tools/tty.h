#ifndef __TTY_H__
    #define __TTY_H__

/**
 *      This is TTY API, it will be used to communicate with the user.
 * Only this file must be includes to use tty
 * 
 */

typedef struct tty_s {
    void (*update)();
    void (*display)();
    void (*new_line)();
    void (*clear)();
} tty_t;

tty_t TTY;

void init_tty();

#endif