#include "shell_intern.h"

/**
 * @brief
 * display actual shell prompt and line
 * 
 */
static void shell_display()
{
    kprint_at("Shell : ", 0, 0, SET_COLOR(WHITE, BLACK));
    kprint_at(shell.prompt, 0, shell.y, SET_COLOR(WHITE, BLACK));
    kprint_at(shell.line, shell.prompt_size, shell.y, SET_COLOR(WHITE, BLACK));
}

/**
 * @brief initialisation of the shell setting all variables
 * 
 */
void shell_init()
{
    for (int i = 0; i < MAX_PROMPT; i++)
        shell.prompt[i] = 0;
    shell.prompt[0] = '>';
    shell.prompt[1] = ' ';
    for (int i = 0; i < MAX_LINE; i++)
        shell.line[i] = 0;
    shell.line_size = 0;
    shell.prompt_size = 2;
    shell.y = 1;
    shell_display();
}

/**
 * @brief 
 * called by keyboard drivers callback, compute shell logic
 * 
 * @param c : char to compute
 */
void shell_input(char c)
{
    switch (c) {
        case '\n':                          // Not saving lines for now, only
            exec(shell.line);
            clear_line();
            break_line();
            break;
        case '\b':
            shell.line[shell.line_size - 1] = 0;
            shell.line_size -= shell.line_size > 0 ? 1 : 0;
            kprint_at(" ", shell.line_size + shell.prompt_size, shell.y, SET_COLOR(WHITE, BLACK));
            break;
        default:
            if (c != 0)
                shell.line[shell.line_size++] = c;
            break;
    }
    shell_display();
}
