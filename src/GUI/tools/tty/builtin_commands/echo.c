#include "echo.h"

int echo_command(char **args)
{
    if (!args[1] || !args[2]) {
        return (1);
    }
    files_t *file = FILES.get_folder(args[1]);
    char *message = join(&args[2], " ");
    FILES.write(file, message);
    return (0);
}