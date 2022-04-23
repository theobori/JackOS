#ifndef __GDT_H__
    #define __GDT_H__

    #include "types.h"

    #define NO_GDT_DESCRIPTORS     8

typedef struct {
    u16 segment_limit;              // segment limit first 0-15 bits
    u16 base_low;                   // base first 0-15 bits
    u8 base_middle;                 // base 16-23 bits
    u8 access;                      // access byte
    u8 granularity;                 // high 4 bits (flags) low 4 bits (limit 4 last bits)(limit is 20 bit wide)
    u8 base_high;                   // base 24-31 bits
} __attribute__((packed)) GDT;

typedef struct {
    u16 limit;                      // limit size of all GDT segments
    u32 base_address;               // base address of the first GDT segment
} __attribute__((packed)) GDT_PTR;

GDT g_gdt[NO_GDT_DESCRIPTORS];
GDT_PTR g_gdt_ptr;

extern void load_gdt(u32 gdt_ptr);

void gdt_set_entry(int index, u32 base, u32 limit, u8 access, u8 gran);
void gdt_init();

#endif
