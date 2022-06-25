#include "mkdir.h"

int mkdir_command(char **args)
{
    if (!args[1])
        return (1);
    char *name = args[1];
    files_t *curr_folder = FILES.get_folder(FILES.curr_pwd);
    int found = 0;
    for (size_t i = 0; curr_folder->next[i]; i++) {
        if (strcmp(curr_folder->next[i]->name, name)) {
            found = 1;
            break;
        }
    }
    if (found) {
        return (1);
    }
    size_t new_file_index = 0;
    for (; curr_folder->next[new_file_index]; new_file_index++);
    curr_folder->next[new_file_index] = malloc(sizeof(files_t));
    size_t name_len = strlen(name) + 1;
    curr_folder->next[new_file_index]->name = malloc(sizeof(char) * name_len);
    memset(curr_folder->next[new_file_index]->name, 0, name_len);
    strcpy(curr_folder->next[new_file_index]->name, name);
}