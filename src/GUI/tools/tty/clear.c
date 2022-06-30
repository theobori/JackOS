#include "clear.h"

void tty_clear()
{
    for (size_t i = 0; i < this.buff_h; i++) {
        for (size_t j = 0; j < this.buff_w; j++) {
            this.buffer[i][j] = 0;
        }
    }
    init_tty();
}