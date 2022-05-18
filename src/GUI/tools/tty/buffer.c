#include "buffer.h"

/**
 * @brief Jump a line in the buffer
 * 
 */
void tty_newline()
{
    if (this.cy < this.buff_h) {
        this.cy++;
        this.cx = 0;
    }
}

void tty_delete_last_char()
{
    if (this.cx > 0) {
        this.cx--;
        this.buffer[this.cy][this.cx] = ' ';
    }
}

/**
 * @brief Add a character to the buffer
 * 
 * @param c : character to add
 */
void tty_add_buff(char c)
{
    this.buffer[this.cy][this.cx] = c;
    this.cx++;
}
