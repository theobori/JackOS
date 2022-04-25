#include "screen_intern.h"

/**
 * @brief 
 * 
 * kprint_at exist to print strings into the VGA screen.
 * 
 * @param str : string to print
 * @param x : x position
 * @param y : y position
 * @param color : color of the text
 */
void kprint_at(const char *str, unsigned short x, unsigned short y, unsigned char color)
{
    char *video_memory = (char *) VGA_ADRESS;

    for (int i = 0; str[i]; ++i) {
        video_memory[(y * MAX_COLS + x + i) * 2] = str[i];
        video_memory[(y * MAX_COLS + x + i) * 2 + 1] = color;
    }
}

/**
 * @brief 
 * 
 * kclear_screen exist to clear the screen.
 * 
 * @param color : color of the background
 */
void kclear_screen(unsigned char color)
{
    char *video_memory = (char *) VGA_ADRESS;

    for (int h = 0; h < MAX_ROWS; ++h) {
        for (int w = 0; w < MAX_COLS; ++w) {
            video_memory[(h * MAX_COLS + w) * 2] = ' ';
            video_memory[(h * MAX_COLS + w) * 2 + 1] = color;
        }
    }
}

/**
 * @brief 
 * 
 * kprint_int_at exist to print an integer into the VGA screen.
 * convert n into ascii char
 * 
 * @param n : integer to print
 * @param x : x position
 * @param y : y position
 * @param color : color of the text
 */
void kprint_int_at(const int n, unsigned short x, unsigned short y, unsigned char color)
{
    char str[10];
    int i = 9;
    int replicate = n;

    do {
        str[i--] = replicate % 10 + '0';
        replicate /= 10;
    } while (replicate);
    kprint_at(str + i + 1, x, y, color);
}

/**
 * @brief set cursor on the screen
 * 
 * @param x : x position
 * @param y : y position
 */
void kset_cursor_pos(u8 x, u8 y)
{
    u16 cursorLocation = y * 80 + x;

    port_byte_out(0x3d4, 14);
    port_byte_out(0x3d5, cursorLocation >> 8);
    port_byte_out(0x3d4, 15);
    port_byte_out(0x3d5, cursorLocation);
}


/**
 * @brief disable cursor
 * 
 */
void kdisable_cursor()
{
    port_byte_out(0x3d4, 10);
    port_byte_out(0x3d5, 32);
}
