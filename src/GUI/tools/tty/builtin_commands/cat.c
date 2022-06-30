#include "cat.h"

int cat_command(char **args)
{
    if (!args[1]) {
        return (1);
    }
    files_t *file = FILES.get_folder(args[1]);
    char *message = FILES.read(file);
    tty_newline(0, 0);
    tty_add_buff_str(message);
    return (0);
}