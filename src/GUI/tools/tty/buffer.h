#ifndef __TTY_BUFFER_H__
    #define __TTY_BUFFER_H__

    #include "intern.h"
    #include "utils/string.h"
    #include "commands.h"

void tty_newline(int with_command, int with_prompt);
void tty_add_buff(char c);
void tty_add_buff_str(char *str);
void tty_delete_last_char();
void tty_set_prompt_in_buffer();

#endif