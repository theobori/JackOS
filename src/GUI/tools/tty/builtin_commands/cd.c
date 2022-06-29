#include "cd.h"

int cd_command(char **args)
{
    if (!args[1]) {
        return (1);
    }
    FILES.change_dir(args[1]);
    return (0);
}