#ifndef __BIOS_H__
    #define __BIOS_H__

    #include "interrupts/isr.h"

    #define BIOS_CONVENTIONAL_MEMORY 0x7e00

void bios32_init();
// bios interrupt call
void int86(u8 interrupt, registers_16_t *in, registers_16_t *out);

#endif