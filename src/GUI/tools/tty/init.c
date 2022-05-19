#include "init.h"

/**
 * @brief fill the prompt attributes with default values
 * 
 * @param prompt : prompt to display
 */
static void fill_prompt(const char *prompt)
{
    for (size_t i = 0; prompt[i]; i++) {
        this.prompt[i] = prompt[i];
    }
}

/**
 * @brief Initialize the tty
 * 
 */
void init_tty()
{
    this.cx = 0;
    this.cy = 0;
    this.buff_w = 100;
    this.buff_h = 37;
    memset(this.prompt, 0, 100);
    memset(this.prompt_index, -1, 37);
    memset(this.test_cmd, 0, 2000);
    fill_prompt("$> ");
    for (size_t i = 0; i < this.buff_h; i++) {
        memset(this.buffer[i], ' ', this.buff_w);
        this.buffer[i][this.buff_w - 1] = 0;
    }
    tty_set_prompt_in_buffer();
    TTY.new_line = &tty_newline;
    TTY.display = &tty_display;
    TTY.update = &update;
    TTY.display();
}