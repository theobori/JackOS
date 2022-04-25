#include "draw_square.h"

void daniel_draw_square(u16 x, u16 y, u16 size, u32 color) {
    for (u16 i = x; i < x + size; ++i) {
        for (u16 j = y; j < y + size; ++j) {
            daniel_putpixel(i, j, color);
        }
    }
}