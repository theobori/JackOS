#include "buffer.h"

void tty_set_prompt_in_buffer()
{
    for (size_t i = 0; this.prompt[i]; i++) {
        this.buffer[this.cy][i] = this.prompt[i];
    }
    this.cx += strlen(this.prompt);

    size_t index = 0;
    while (this.prompt[index] == -1) {
        index++;
    }
    this.prompt_index[index] = this.cy;
}

/**
 * @brief Jump a line in the buffer
 * 
 */
void tty_newline(int with_command, int with_prompt)
{
    if (this.cy < this.buff_h) {
        if (with_command) {
            launch_command(this.buffer[this.cy]);
        }
        this.cy++;
        this.cx = 0;
        if (with_prompt) {
            tty_set_prompt_in_buffer();
        }
    }
}

static int want_delete_prompt()
{
    int have_prompt = 0;

    for (size_t i = 0; this.prompt_index[i] != -1; i++) {
        if (this.prompt_index[i] == this.cy) {
            have_prompt = 1;
            break;
        }
    }
    if (!have_prompt)
        return (0);
    if (this.cx <= strlen(this.prompt))
        return (1);
    return (0);
}

/**
 * @brief Add a char in the buffer
 * 
 */
void tty_delete_last_char()
{
    if (want_delete_prompt())
        return;
    if (this.cx > 0) {
        this.cx--;
        this.buffer[this.cy][this.cx] = ' ';
    } else {
        if (this.cy > 0) {
            this.cy--;
            this.cx = this.buff_w - 1;
            this.buffer[this.cy][this.cx] = ' ';
        }
    }
}

/**
 * @brief Add a character to the buffer
 * 
 * @param c : character to add
 */
void tty_add_buff(char c)
{
    if (this.cx >= this.buff_w) {
        this.cx = 0;
        this.cy++;
    }
    this.buffer[this.cy][this.cx] = c;
    this.cx++;
}

void tty_add_buff_str(char *str)
{
    for (size_t i = 0; str[i]; i++) {
        tty_add_buff(str[i]);
    }
}