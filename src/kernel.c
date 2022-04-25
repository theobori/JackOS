#include "kernel.h"

/**
 * @brief entry point of kernel
 * 
 */
void kmain()
{
    gdt_init();
    isr_install();
    init_timer(50);
    init_daniel();
    init_keyboard();
    init_mouse();
    shell_init();

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            GUI.put_pixel(i, j, D_LIGHT_CYAN);
        }
    }
}
