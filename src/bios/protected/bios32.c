#include "bios32.h"

/**
 * @brief init bios32 routine by setting 6 & 7 the entries
 * this data will be copied when bios32_service() is called
 */
void bios32_init()
{
    gdt_set_entry(6, (base_t){0, 0, 0}, 0xffffffff, 0x9a, 0x0f);        // Adding two more entries to the GDT
    gdt_set_entry(7, (base_t){0, 0, 0}, 0xffffffff, 0x92, 0x0f);
    gdt32.base_address = (u32)g_gdt;                                    // Creating new gdt
    gdt32.limit = sizeof(g_gdt) - 1;
    idt32.base = 0;                                                     // Creating new idt
    idt32.limit = 0x3ff;
}

/**
 * @brief copy data to assembly bios32_call.asm and execute code from 0x7c00 address
 * 
 * @param interrupt : interrupt number
 * @param in : input registers
 * @param out : output registers
 */
void bios32_service(u8 interrupt, registers_16_t *in, registers_16_t *out)
{
    void *offset = (void *)0x7c00;

    memcpy(&gdt_entries_32, g_gdt, sizeof(g_gdt));                          // copy our GDT entries g_gdt to gdt_entries_32(bios32_call.asm)
    gdt32.base_address = (u32)REBASE_ADDRESS(&gdt_entries_32);              // set base of gdt_entries_32(bios32_call.asm) starting from 0x7c00
    memcpy(&bios32_gdt_ptr, &gdt32, sizeof(GDT_PTR));                       // copy gdt32 to bios32_gdt_ptr(bios32_call.asm)
    memcpy(&bios32_idt_ptr, &idt32, sizeof(idt_register_t));                // copy idt32 to bios32_idt_register_t(bios32_call.asm)
    memcpy(&bios32_in_reg16_ptr, in, sizeof(registers_16_t));               // copy all 16 bit in registers to bios32_in_reg16_ptr(bios32_call.asm)
    memcpy(&bios32_int_number_ptr, &interrupt, sizeof(u8));                 // copy bios interrupt number to bios32_int_number_ptr(bios32_call.asm)
    memcpy(offset, BIOS32_START, (u32)BIOS32_END - (u32)BIOS32_START);      // copy bios32_call.asm code to offset address
    exec_bios32_function();                                                 // execute the code from 0x7c00
    void *in_reg16_address = REBASE_ADDRESS(&bios32_out_reg16_ptr);         // copy output registers to out
    memcpy(out, in_reg16_address, sizeof(registers_16_t));
    gdt_init();                                                             // re-initialize the gdt and idt
    isr_install();
}

/**
 * @brief bios interrupt call
 * 
 * @param interrupt : interrupt number
 * @param in : input registers
 * @param out : output registers
 */
void int86(u8 interrupt, registers_16_t *in, registers_16_t *out)
{
    bios32_service(interrupt, in, out);
}
