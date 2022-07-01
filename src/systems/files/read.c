#include "read.h"

char *read(files_t *file)
{
    return ((char *)file->block);
}