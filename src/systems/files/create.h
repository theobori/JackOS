#ifndef __FILE_CREATE_H__
    #define __FILE_CREATE_H__

    #include "utils/memory.h"
    #include "utils/string.h"
    #include "intern.h"
    #include "list.h"

int new_file(const char *file_path);
int create_empty_file(files_t *file, const char *name);

#endif