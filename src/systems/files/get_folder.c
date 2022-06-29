#include "get_folder.h"

files_t *get_folder(char *path)
{
    char **folders = split(path, "/");
    files_t *folder = &files;
    for (size_t i = 0; folders[i]; i++) {
        for (size_t j = 0; folder->next[j]; j++) {
            if (strcmp(folder->next[j]->name, folders[i])) {
                folder = folder->next[j];
                break;
            }
        }
    }
    return (folder);
}