#include "write.h"

int write(files_t *file, char *content)
{
    memset(file->block, 0, sizeof(char) * BLOCK_SIZE);
    memcpy(file->block, content, sizeof(char) * strlen(content));
}