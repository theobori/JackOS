#include "clear.h"

/**
 * @brief
 * Enter key, jump lines
 * 
 */
void break_line()
{
    shell.y++;
}

/**
 * @brief 
 * reset actual shell line
 * 
 */
void clear_line()
{
    for (unsigned int i = 0; i < shell.line_size; i++)
        shell.line[i] = 0;
    shell.line_size = 0;
}