#include "draw_char.h"

char font[NB_CHAR][CHAR_NB_LINES][CHAR_NB_COLS] = {
    #include "../fonts/daniel.font"
};

/**
 * @brief Draw a character at a given position
 * 
 * @param c : Character to draw
 * @param x : x position
 * @param y : y position
 * @param color : color of the character
 */
void daniel_draw_char_at_pos(char c, int x, int y, u32 color)
{
    if (x >= WINDOW_W || y >= WINDOW_H)
        return;
    char *letter = (&daniel_font) + c * CHAR_NB_LINES;

    for (size_t i = 0; i < CHAR_NB_LINES; i++) {
        char byte = *(letter + i);
        for (size_t j = 0; j < CHAR_NB_COLS; j++, byte >>= 1) {
            if (byte & 1) {
                daniel_putpixel(x + 8 - j, y + i, D_WHITE);
            } else {
                daniel_putpixel(x + 8 - j, y + i, D_BLACK);
            }
        }
    }
}

/**
 * @brief draw a formatted string at a given position
 * 
 * @param x : x position
 * @param y : y position
 * @param format : format string
 * @param ... : arguments
 */
void daniel_printf_at(size_t x, size_t y, char *format, ...)
{
    void *begin = &format;
    int print_coord = x;

    begin += sizeof(char *);
    for (size_t i = 0; format[i]; i++) {
        if (format[i] == '%') {
            i++;
            if (format[i] == 'c') {
                char c = *(char *)begin;
                begin += sizeof(char);
                daniel_draw_char_at_pos(c, print_coord, y, D_WHITE);
                print_coord += 8;
            } else if (format[i] == 's') {
                char *str = *(char **)begin;
                begin += sizeof(char *);
                for (size_t i = 0; str[i]; i++) {
                    daniel_draw_char_at_pos(str[i], print_coord, y, D_WHITE);
                    print_coord += 8;
                }
            }
        } else {
            daniel_draw_char_at_pos(format[i], print_coord, y, D_WHITE);
            print_coord += 8;
        }
    }
}