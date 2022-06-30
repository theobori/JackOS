#ifndef __TTY_COMMANDS_H__
    #define __TTY_COMMANDS_H__

    #include "intern.h"
    #include "buffer.h"
    #include "builtin_commands/ping.h"
    #include "builtin_commands/pwd.h"
    #include "builtin_commands/ls.h"
    #include "builtin_commands/mkdir.h"
    #include "builtin_commands/cd.h"
    #include "builtin_commands/clear.h"
    #include "utils/memory.h"

void launch_command(const char *command);

#endif