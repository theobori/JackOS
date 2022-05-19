#include "init.h"

void init_file_system()
{
    create_empty_file(&files, "/");
    FILES.create = &new_file;
    FILES.list_dirs = &list_all_dirs;
}