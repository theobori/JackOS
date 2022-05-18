#ifndef __GUI_H__
    #define __GUI_H__

    #include "types.h"

/*
**                  This is Daniel's GUI Api
**          It is a simple api for drawing on VESA/VBE mode
**          This must be the only file to include for drawing
**          functions
*/

    #define RGB_COLOR(r, g, b) (r << 16 | g << 8 | b)
    #define WINDOW_W 800
    #define WINDOW_H 600


typedef enum Daniel_color_e {
    D_WHITE = RGB_COLOR(255, 255, 255),
    D_BLACK = RGB_COLOR(0, 0, 0),
    D_RED = RGB_COLOR(255, 0, 0),
    D_BLUE = RGB_COLOR(0, 0, 255),
    D_GREEN = RGB_COLOR(0, 255, 0),
    D_YELLOW = RGB_COLOR(255, 255, 0),
    D_CYAN = RGB_COLOR(0, 255, 255),
    D_MAGENTA = RGB_COLOR(255, 0, 255),
    D_LIGHT_GRAY = RGB_COLOR(200, 200, 200),
    D_GRAY = RGB_COLOR(100, 100, 100),
    D_LIGHT_RED = RGB_COLOR(255, 100, 100),
    D_LIGHT_BLUE = RGB_COLOR(100, 100, 255),
    D_LIGHT_GREEN = RGB_COLOR(100, 255, 100),
    D_LIGHT_YELLOW = RGB_COLOR(255, 255, 100),
    D_LIGHT_CYAN = RGB_COLOR(100, 255, 255),
    D_LIGHT_MAGENTA = RGB_COLOR(255, 100, 255)
} Daniel_color_t;

typedef struct Daniel_s {
    int g_selected_mode;
    u32 *g_vbe_buffer;
    void (*put_pixel)(int x, int y, u32 color);
    void (*draw_square)(u16 x, u16 y, u16 size, u32 color);
    void (*draw_char_at_pos)(char c, int x, int y, u32 color);
    void (*printf)(size_t x, size_t y, char *format, ...);
    u32 g_width, g_height;
} Daniel_t;

Daniel_t GUI;

void init_daniel();

#endif