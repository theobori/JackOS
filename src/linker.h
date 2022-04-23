#ifndef __LINKER_H__
    #define __LINKER_H__

// symbols from linker.ld for section addresses
extern u8 __kernel_section_start;
extern u8 __kernel_section_end;
extern u8 __kernel_text_section_start;
extern u8 __kernel_text_section_end;
extern u8 __kernel_data_section_start;
extern u8 __kernel_data_section_end;
extern u8 __kernel_rodata_section_start;
extern u8 __kernel_rodata_section_end;
extern u8 __kernel_bss_section_start;
extern u8 __kernel_bss_section_end;

#endif