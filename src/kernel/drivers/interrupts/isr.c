#include "isr.h"

/**
 * @brief set all the handler to the idt (handler are in interrupts.asm)
 * We cannot do loop because we need adress of them
 * 
 */
void isr_install() {
    set_idt_gate(0, (unsigned int)isr0);
    set_idt_gate(1, (unsigned int)isr1);
    set_idt_gate(2, (unsigned int)isr2);
    set_idt_gate(3, (unsigned int)isr3);
    set_idt_gate(4, (unsigned int)isr4);
    set_idt_gate(5, (unsigned int)isr5);
    set_idt_gate(6, (unsigned int)isr6);
    set_idt_gate(7, (unsigned int)isr7);
    set_idt_gate(8, (unsigned int)isr8);
    // set_idt_gate(9, (unsigned int)isr9);
    // set_idt_gate(10, (unsigned int)isr10);
    // set_idt_gate(11, (unsigned int)isr11);
    // set_idt_gate(12, (unsigned int)isr12);
    // set_idt_gate(13, (unsigned int)isr13);
    // set_idt_gate(14, (unsigned int)isr14);
    // set_idt_gate(15, (unsigned int)isr15);
    // set_idt_gate(16, (unsigned int)isr16);
    // set_idt_gate(17, (unsigned int)isr17);
    // set_idt_gate(18, (unsigned int)isr18);
    // set_idt_gate(19, (unsigned int)isr19);
    // set_idt_gate(20, (unsigned int)isr20);
    // set_idt_gate(21, (unsigned int)isr21);
    // set_idt_gate(22, (unsigned int)isr22);
    // set_idt_gate(23, (unsigned int)isr23);
    // set_idt_gate(24, (unsigned int)isr24);
    // set_idt_gate(25, (unsigned int)isr25);
    // set_idt_gate(26, (unsigned int)isr26);
    // set_idt_gate(27, (unsigned int)isr27);
    // set_idt_gate(28, (unsigned int)isr28);
    // set_idt_gate(29, (unsigned int)isr29);
    // set_idt_gate(30, (unsigned int)isr30);
    // set_idt_gate(31, (unsigned int)isr31);
    set_idt();                                      // Load all the idt into memory
}

// Temp
char *exception_messages[] = {
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",

    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",

    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",

    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};

/**
 * @brief all the handler will be finally call this function with interrupts id
 * 
 * @param r : all the registers from the interrupt
 *
 */
void isr_handler(registers_t r) {
    static int y = 0;
    kprint("received interrupt: ", 0, y++, SET_COLOR(WHITE, BLACK));
    char s[3];
    itoa(r.int_no, s);
    kprint(s, 0, 1, SET_COLOR(WHITE, BLACK));
    kprint(exception_messages[r.int_no], 0, 2 + y++, SET_COLOR(WHITE, BLACK));
}
