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
    for (int i = 0; i < CHAR_NB_LINES; i++) {
        for (int j = 0; j < CHAR_NB_COLS; j++) {
            if (font[c - 32][i][j] == 1) {
                daniel_putpixel(x + j, y + i, color);
            } else {
                daniel_putpixel(x + j, y + i, D_BLACK);
            }
        }
    }
}