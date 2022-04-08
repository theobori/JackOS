#include "exec.h"

/**
 * @brief 
 * 
 * @param cmd 
 */
void exec(__attribute__((unused))const char *cmd)
{
    kprint_at(UNKNOWN_CMD, 0, ++shell.y, SET_COLOR(WHITE, BLACK));
}