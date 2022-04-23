#include "kernel.h"

/**
 * @brief entry point of kernel
 * 
 */
void kmain()
{
    Daniel_t gui;
    gdt_init();
    isr_install();
    init_timer(50);
    init_keyboard();
    shell_init();
    init_daniel(&gui);
}
