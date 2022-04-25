#ifndef __SHELL_EXEC_H__
    #define __SHELL_EXEC_H__

    #include "drivers/screen.h"
    #include "shell_struct.h"
    #include "utils/string.h"
    #include "builtin_commands.h"
    #include <stddef.h>

    #define UNKNOWN_CMD "Unknown command"
    #define COMMAND_EXECUTED "Command executed"

void exec(const char *cmd);

#endif