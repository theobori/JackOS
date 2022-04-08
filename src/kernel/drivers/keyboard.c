#include "keyboard.h"

char get_char_pressed(unsigned char scancode) {
    char key_pressed_char[58] = {
        ' ', ' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
        '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
        ' ', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', ' ',
        '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', ' ', ' ', ' ', ' '
    };
    return (key_pressed_char[scancode]);
}

static void keyboard_callback(registers_t regs) {
    /* The PIC leaves us the scancode in port 0x60 */
    unsigned char scancode = port_byte_in(0x60);
    kprint("Keyboard scancode: ", 0, 4, SET_COLOR(WHITE, BLACK));
    kprint_int(scancode, 0, 4, SET_COLOR(WHITE, BLACK));
    kprint_int(get_char_pressed(scancode), 0, 5, SET_COLOR(WHITE, BLACK));
}

void init_keyboard() {
   register_interrupt_handler(IRQ(1), keyboard_callback); 
}
