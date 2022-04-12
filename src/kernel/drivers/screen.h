#ifndef __SCREEN_H__
    #define __SCREEN_H__

/*
**              SCREEN DRIVER API
** this is screen driver api for kernel screen,
** it must be the only header to include in kernel
** code
*/

    #define SET_COLOR(fg, bg) bg * 16 + fg  // Give color combination with foreground and background

enum Colors {                               // IMPORTANT :
    BLACK,                                  // KEEP THE ORDER !!
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHT_GRAY,
    GRAY,
    LIGHT_BLUE,
    LIGHT_GREEN,
    LIGHT_CYAN,
    LIGHT_RED,
    LIGHT_MAGENTA,
    YELLOW,
    WHITE
};

void kprint_at(const char *str, unsigned short x, unsigned short y, unsigned char color);
void kprint_int_at(const int n, unsigned short x, unsigned short y, unsigned char color);
void clear_screen(unsigned char color);
void kmove_view(int nb_lines);

#endif