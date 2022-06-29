#include "display.h"

/**
 * @brief Displays the buffer on the screen.
 * 
 */
void tty_display()
{
    for (size_t i = 0; i < this.buff_h; i++) {
        GUI.printf(0, i * 16, this.buffer[i]);
    }
}