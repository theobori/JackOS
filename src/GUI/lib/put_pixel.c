#include "put_pixel.h"

/**
 * @brief Daniel's put pixel function
 * 
 * @param x 
 * @param y 
 * @param color 
 */
void daniel_putpixel(int x, int y, u32 color)
{
    u32 i = y * GUI.g_width + x;
    *(GUI.g_vbe_buffer + i) = color;
}