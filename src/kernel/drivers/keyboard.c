#include "keyboard.h"

/**
 * @brief Get the char pressed object
 * 
 * @param scancode : code of the char being pressed (QWERTY)
 * @return char : char being pressed
 */
static char get_char_pressed(unsigned char scancode)
{
    char key_pressed_char[58] = {
        ' ', ' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '+', '\b',
        '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
        ' ', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', ' ',
        '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', ' ', ' ', ' ', ' '
    };
    if (scancode > 58)
        return (0);
    return (key_pressed_char[scancode]);
}

/**
 * @brief callback for key_pressed, it's been called when a key is pressed
 * for now it's simply doing printing
 * 
 * @param regs 
 */
static void keyboard_callback(registers_t regs)
{
    unsigned char scancode = port_byte_in(0x60);
    shell_input(get_char_pressed(scancode));
}

/**
 * @brief initialization of keyboard driver setting with callback setting
 * and 
 * 
 */
void init_keyboard()
{
   register_interrupt_handler(IRQ(1), keyboard_callback); 
}
