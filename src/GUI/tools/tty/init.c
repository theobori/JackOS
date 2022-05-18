#include "init.h"

void init_tty()
{
    this.cx = 0;
    this.cy = 0;
    this.buff_w = 100;
    this.buff_h = 37;
    for (size_t i = 0; i < this.buff_h; i++) {
        memset(this.buffer[i], ' ', this.buff_w);
        this.buffer[i][this.buff_w - 1] = 0;
    }
    TTY.new_line = &tty_newline;
    TTY.display = &tty_display;
    TTY.update = &update;
}