#include "pwd.h"

int pwd_command(__attribute__((unused))char **args)
{
    tty_newline(0, 0);
    tty_add_buff_str(FILES.curr_pwd);
    return (0);
}