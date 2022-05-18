#include "display.h"

/**
 * @brief Displays the buffer on the screen.
 * 
 */
void tty_display()
{
    for (size_t i = 0; i < this.buff_h; i++) {
        for (size_t j = 0; j < this.buff_w; j++) {
            GUI.draw_char_at_pos(this.buffer[i][j], j * 8, i * 16, D_WHITE);
        }
    }
}