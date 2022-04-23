#include "keyboard_intern.h"

/**
 * @brief Get the char pressed object
 * 
 * @param scancode : code of the char being pressed (QWERTY)
 * @return char : char being pressed
 */
static char get_char_pressed(unsigned char scancode)
{
    char key_pressed_char[NB_LANG][NB_CHAR] = {
        #include "mappers/US.txt"
        #include "mappers/FR.txt"
    };
    if (scancode > 58)
        return (0);
    return (key_pressed_char[curr_lang][scancode]);
}

/**
 * @brief callback for key_pressed, it's been called when a key is pressed
 * for now it's simply doing printing
 * 
 * @param regs 
 */
static void keyboard_callback(__attribute__((unused))registers_t regs)
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

/**
 * @brief changing keyboard language
 * 
 * @param lang : language to change to
 */
void change_lang(const char *lang)
{
    for (int i = 0; i < NB_LANG; i++) {
        if (strcmp(accepted_lang[i], lang))
            curr_lang = (enum Lang)i;
    }
}
