#include "gdt.h"

/**
 * @brief Initialize GDT
 * 
 * @param index : index of GDT entry
 * @param base : base address of GDT entry
 * @param limit : limit of GDT entry
 * @param access : access flags of GDT entry
 * @param gran : granularity of GDT entry
 */
void gdt_set_entry(int index, u32 base, u32 limit, u8 access, u8 gran)
{
    GDT *gdt_entry = &g_gdt[index];

    gdt_entry->segment_limit = limit & 0xFFFF;
    gdt_entry->base_low = base & 0xFFFF;
    gdt_entry->base_middle = (base >> 16) & 0xFF;
    gdt_entry->access = access;

    gdt_entry->granularity = (limit >> 16) & 0x0F;
    gdt_entry->granularity = gdt_entry->granularity | (gran & 0xF0);

    gdt_entry->base_high = (base >> 24 & 0xFF);
}

/**
 * @brief Initialize GDT
 * 
 */
void gdt_init()
{
    g_gdt_ptr.limit = sizeof(g_gdt) - 1;
    g_gdt_ptr.base_address = (u32)g_gdt;

    gdt_set_entry(0, 0, 0, 0, 0);
    // code segment
    gdt_set_entry(1, 0, 0xffffffff, 0x9a, 0xcf);
    // data segment
    gdt_set_entry(2, 0, 0xffffffff, 0x92, 0xcf);
    // user code segment
    gdt_set_entry(3, 0, 0xffffffff, 0xfa, 0xcf);
    // user data segment
    gdt_set_entry(4, 0, 0xffffffff, 0xf2, 0xcf);

    load_gdt((u32)&g_gdt_ptr);
}
