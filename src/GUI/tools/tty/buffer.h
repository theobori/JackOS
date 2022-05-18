#ifndef __TTY_BUFFER_H__
    #define __TTY_BUFFER_H__

    #include "intern.h"

void tty_newline();
void tty_add_buff(char c);
void tty_delete_last_char();

#endif