#include "timer.h"

unsigned int tick = 0;

/**
 * @brief callback every tick passed
 * 
 * @param regs : all the registers
 */
static void timer_callback(__attribute__((unused))registers_t regs)
{
    tick++;
}

/**
 * @brief init cpu timer
 * 
 * @param freq : frequency required
 */
void init_timer(unsigned int freq)
{
    register_interrupt_handler(IRQ(0), timer_callback);
    unsigned int divisor = 1193180 / freq;
    u8 low  = (u8)(divisor & 0xff);
    u8 high = (u8)((divisor >> 8) & 0xff);
    port_byte_out(0x43, 0x36);
    port_byte_out(0x40, low);
    port_byte_out(0x40, high);
}
