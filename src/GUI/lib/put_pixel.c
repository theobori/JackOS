#include "put_pixel.h"

/**
 * @brief Daniel's put pixel function
 * 
 * @param x 
 * @param y 
 * @param color 
 */
void daniel_putpixel(Daniel_t *this, int x, int y, u32 color)
{
    u32 i = y * this->g_width + x;
    *(this->g_vbe_buffer + i) = color;
}