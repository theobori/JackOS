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
    kprint("Hello, kernel!", 0, 1, SET_COLOR(RED, WHITE));
    kprint_int(42, 0, 2, SET_COLOR(GREEN, WHITE));
    isr_install();
    __asm__ __volatile__("int $2");
    __asm__ __volatile__("int $3");
}
