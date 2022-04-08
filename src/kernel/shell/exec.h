#ifndef __SHELL_EXEC_H__
    #define __SHELL_EXEC_H__

    #include "utils/print.h"
    #include "shell_struct.h"

    #define UNKNOWN_CMD "Unknown command"

void exec(const char *cmd);

#endif