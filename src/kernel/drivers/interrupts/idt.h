#ifndef __IDT_H__
    #define __IDT_H__

    #define KERNEL_CODE_SEGMENT 0x08
    #define IDT_ENTRIES 256

typedef struct idt_gate_s {
    unsigned short low_offset;                  // low byte of handler function
    unsigned short selector;                    // kernel code segment offset
    unsigned char always0;                      // always 0
    unsigned char flags;                        // flags
    unsigned short high_offset;                 // high byte of handler function
} __attribute__((packed))idt_gate_t;

typedef struct idt_register_s {
    unsigned short limit;                       // size of idt
    unsigned int base;                          // base address of idt
} __attribute__((packed)) idt_register_t;

idt_gate_t idt[IDT_ENTRIES];
idt_register_t idt_reg;

void set_idt_gate(int n, unsigned int handler);
void set_idt();

#endif
