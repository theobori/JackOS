#include "keyboard_intern.h"

/**
 * @brief Get the char pressed object
 * 
 * @param scancode : code of the char being pressed (QWERTY)
 * @return char : char being pressed
 */
static char convert_scancode_to_char(unsigned char scancode)
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
 * @brief call all the callbacks functions
 * 
 * @param c : char to pass to the callback functions
 */
static void call_callbacks(char c)
{
    for (size_t i = 0; i < callback_index; i++) {
        callbacks[i](c);
    }
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
    char char_pressed = convert_scancode_to_char(scancode);

    shell_input(char_pressed);
    if (char_pressed > 0) {
        call_callbacks(char_pressed);
    }
}

/**
 * @brief initialization of keyboard driver setting with callback setting
 * and 
 * 
 */
void init_keyboard()
{
    for (int i = 0; i < MAX_CALLBACKS; i++) {
        callbacks[i] = NULL;
    }
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

/**
 * @brief Set the callback into callback list
 * 
 * @param callback : callback to set
 */
void get_char_pressed(void (*callback)(char))
{
    if (callback_index >= MAX_CALLBACKS)
        return;
    callbacks[callback_index++] = callback;
}