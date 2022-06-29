#ifndef __FILE_LIST_H__
    #define __FILE_LIST_H__

    #include "intern.h"
    #include "utils/string.h"
    #include "utils/memory.h"

char **list_all_dirs(const char *path);
files_t *find_next_folder(files_t *folder, const char *name);
size_t count_files(files_t *folder);

#endif