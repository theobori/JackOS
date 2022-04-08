#include "print.h"

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
 * clear_screen exist to clear the screen.
 * 
 * @param color : color of the background
 */
void clear_screen(unsigned char color)
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
 * kprint_at_int_at exist to print an integer into the VGA screen.
 * convert n into ascii char
 * 
 * @param n : integer to print
 * @param x : x position
 * @param y : y position
 * @param color : color of the text
 */
void kprint_at_int_at(const int n, unsigned short x, unsigned short y, unsigned char color)
{
    char *video_memory = (char *) VGA_ADRESS;
    char str[10];
    int i = 9;
    int replicate = n;

    do {
        str[i--] = replicate % 10 + '0';
        replicate /= 10;
    } while (replicate);
    kprint_at(str + i + 1, x, y, color);
}