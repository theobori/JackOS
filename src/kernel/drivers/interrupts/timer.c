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
    // kprint_at("Tick: ", 0, 0, SET_COLOR(WHITE, GREEN));
    // kprint_int_at(tick, 10, 0, SET_COLOR(WHITE, GREEN));
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
    unsigned char low  = (unsigned char)(divisor & 0xff);
    unsigned char high = (unsigned char)((divisor >> 8) & 0xff);
    port_byte_out(0x43, 0x36);
    port_byte_out(0x40, low);
    port_byte_out(0x40, high);
}
