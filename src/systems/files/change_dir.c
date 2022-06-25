#include "change_dir.h"

int change_dir(char *path)
{
    files_t *curr_folder = NULL;
    char **folders = NULL;
    int start_from_root = path[0] == '/' ? 1 : 0;
    if (start_from_root) {
        FILES.curr_pwd = malloc(sizeof(char) * (strlen(path) + 1));
        strcpy(FILES.curr_pwd, path);
        path++;
    } else {
        size_t added_len = 0;
        folders = split(path, "/");
        for (size_t i = 0; folders[i]; i++) {
            added_len += strlen(folders[i]);
            if (folders[i + 1]) {
                added_len++;
            }
        }
        size_t curr_pwd_len = strlen(FILES.curr_pwd) + 1;
        char *temp_path = malloc(sizeof(char) * curr_pwd_len);
        memset(temp_path, 0, curr_pwd_len);
        strcpy(temp_path, FILES.curr_pwd);
        FILES.curr_pwd = malloc(sizeof(char) * (curr_pwd_len + added_len + 1));
        strcpy(FILES.curr_pwd, temp_path);
        for (size_t i = 0; folders[i]; i++) {
            strcat(FILES.curr_pwd, folders[i]);
            if (folders[i + 1]) {
                FILES.curr_pwd[strlen(FILES.curr_pwd) - 1] = '/';
            }
        }
    }
    return (1);
}