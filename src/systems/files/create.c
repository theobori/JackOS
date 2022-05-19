#include "create.h"

int create_empty_file(files_t *file, const char *name)
{
    if (strlen(name) > NAME_SIZE) {
        return (0);
    }
    file->block = malloc(sizeof(char) * (BLOCK_SIZE + 1));
    file->name = malloc(sizeof(char) * (NAME_SIZE + 1));
    file->next = malloc(sizeof(files_t *) * (MAX_FILES + 1));
    memset(file->name, 0, NAME_SIZE + 1);
    memset(file->block, 0, BLOCK_SIZE + 1);
    for (size_t i = 0; i < MAX_FILES + 1; i++) {
        file->next[i] = NULL;
    }
    strcpy(file->name, name);
    return (1);
}

int new_file(const char *file_path)
{
    char **names = split(file_path, "/");
    files_t *head = &files;

    for (size_t i = 0; names[i]; i++) {
        files_t *next_folder = find_next_folder(head, names[i]);
        if (next_folder) {
            head = next_folder;
        } else {
            if (names[i + 1])
                return (0);
            for (size_t j = 0; j < MAX_FILES; j++) {
                if (head->next[j] == NULL) {
                    head->next[j] = malloc(sizeof(files_t));
                    return (create_empty_file(head->next[j], names[i]));
                }
            }
        }
    }
    return (0);
}
