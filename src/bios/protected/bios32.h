#ifndef __BIOS32_H__
    #define __BIOS32_H__

    #include "types.h"
    #include "interrupts/idt.h"
    #include "gdt.h"
    #include "utils/memory.h"
    #include "../bios.h"

    #define REBASE_ADDRESS(x)  (void*)(0x7c00 + (void*)x - (u32)BIOS32_START)

// defined in bios32_call.asm
extern void BIOS32_START();
extern void BIOS32_END();
extern void *bios32_gdt_ptr;
extern void *gdt_entries_32;
extern void *bios32_idt_ptr;
extern void *bios32_in_reg16_ptr;
extern void *bios32_out_reg16_ptr;
extern void *bios32_int_number_ptr;

idt_register_t gdt32;
idt_register_t idt32;

extern GDT g_gdt[NO_GDT_DESCRIPTORS];

void (*exec_bios32_function)() = (void *)0x7c00;


#endif
