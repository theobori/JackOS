#include "idt.h"

/**
 * @brief Set the idt gate object with handler
 * 
 * @param n : index of the idt gate
 * @param handler : function handler of the idt gate
 */
void set_idt_gate(int n, unsigned int handler)
{
    idt[n].low_offset = handler & 0xffff;
    idt[n].selector = KERNEL_CODE_SEGMENT;
    idt[n].always0 = 0;
    idt[n].flags = 0x8e;
    idt[n].high_offset = (handler >> 16) & 0xffff;
}

/**
 * @brief Set the idt register object into memory
 * 
 */
void set_idt()
{
    idt_reg.base = (unsigned int)&idt;
    idt_reg.limit = IDT_ENTRIES * sizeof(idt_gate_t) - 1;
    __asm__ __volatile__("lidt (%0)" : : "r" (&idt_reg));
}
