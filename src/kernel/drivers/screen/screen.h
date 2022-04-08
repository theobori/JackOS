#ifndef __SCREEN_H__
    #define __SCREEN_H__

/*
**              SCREEN DRIVER API
** this is screen driver api for kernel screen,
** it must be the only header to include in kernel
** code
*/

void kprint_at(const char *str, unsigned short x, unsigned short y, unsigned char color);
void kprint_at_int_at(const int n, unsigned short x, unsigned short y, unsigned char color);
void clear_screen(unsigned char color);

#endif