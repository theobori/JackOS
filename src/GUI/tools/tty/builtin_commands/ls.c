#include "ls.h"

int ls_command(char **args)
{
    tty_newline(0, 0);
    char **files = FILES.list_dirs(FILES.curr_pwd);

    for (size_t i = 0; files[i]; i++) {
        tty_add_buff_str(files[i]);
        if (files[i + 1]) {
            tty_newline(0, 0);
        }
    }
    return (0);
}