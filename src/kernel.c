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
    init_keyboard();
    init_mouse();
    shell_init();
    init_daniel();
    init_tty();
    init_file_system();

    TTY.update();
}
