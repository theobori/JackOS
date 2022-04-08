#include "entry.h"

/**
 * @brief 
 * 
 * this is the kernel entry point.
 * it can also be called by the main function.
 * 
 */
void kernel_entry() {
    clear_screen(SET_COLOR(WHITE, BLACK));
    isr_install();
    __asm__ __volatile__("sti");
    init_timer(50);
    init_keyboard();
}
