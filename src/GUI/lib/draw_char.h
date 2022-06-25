#ifndef __DRAW_CHAR_H__
    #define __DRAW_CHAR_H__

    #include "../GUI.h"
    #include "put_pixel.h"
    #include "draw_square.h"
    #include "utils/string.h"

    #include "types.h"

    #define NB_CHAR 97
    #define CHAR_NB_LINES 16
    #define CHAR_NB_COLS 8

void daniel_draw_char_at_pos(char c, int x, int y, u32 color);
void daniel_printf_at(size_t x, size_t y, char *format, ...);
void test(const char c);

extern char daniel_font;

#endif