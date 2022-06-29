#include "list.h"

files_t *find_next_folder(files_t *folder, const char *name)
{
    for (size_t i = 0; i < MAX_FILES; i++) {
        if (folder->next[i] != NULL) {
            if (strcmp(folder->next[i]->name, name)) {
                return (folder->next[i]);
            }
        }
    }
    return (NULL);
}

size_t count_files(files_t *folder)
{
    size_t count = 0;

    for (size_t i = 0; i < MAX_FILES; i++) {
        if (folder->next[i]) {
            count++;
        }
    }
    return (count);
}

char **list_all_dirs(const char *path)
{
    char **dirs = NULL;
    size_t dir_index = 0;
    char **names = split(path, "/");
    files_t *head = &files;

    for (size_t i = 0; names[i]; i++) {
        files_t *next_folder = find_next_folder(head, names[i]);
        if (next_folder) {
            head = next_folder;
        } else {
            return (NULL);
        }
    }
    const size_t nb_dirs = count_files(head);
    dirs = malloc(sizeof(char *) * (nb_dirs + 1));
    dirs[nb_dirs] = NULL;
    for (size_t i = 0; i < MAX_FILES; i++) {
        if (head->next[i]) {
            dirs[dir_index++] = head->next[i]->name;
        }
    }
    return (dirs);
}
