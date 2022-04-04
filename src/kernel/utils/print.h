#ifndef __PRINT_H__
    #define __PRINT_H__

    #define VGA_ADRESS 0xB8000              // VGA adress start here (for display)
    #define MAX_COLS 80                     // Max number of columns
    #define MAX_ROWS 25                     // Max number of rows

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

void kprint(const char *str, unsigned short x, unsigned short y, unsigned char color);
void kprint_int(const int n, unsigned short x, unsigned short y, unsigned char color);
void clear_screen(unsigned char color);

#endif