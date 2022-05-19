#ifndef __TTY_COMMANDS_H__
    #define __TTY_COMMANDS_H__

    #include "intern.h"
    #include "buffer.h"
    #include "builtin_commands/ping.h"
    #include "utils/memory.h"

void launch_command(const char *command);

#endif