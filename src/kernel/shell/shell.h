#ifndef __SHELL_H__
    #define __SHELL_H__

    #include "utils/print.h"
    #include "drivers/keyboard.h"
    #include "shell_struct.h"
    #include "clear.h"

void shell_init();
void shell_input(char c);

#endif