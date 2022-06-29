#include "dir_exist.h"

static char **parse_folder(char *dir)
{
    char **res = NULL;
    if (dir[0] == '/') {
        return (res);
    }
    res = split(dir, "/");
    return (res);
}

static files_t *move_to_curr_folder(char *curr_dir)
{
    files_t *temp = &files;
    char **folders = split(curr_dir, "/");
    for (int i = 0; temp->next[i]; i++) {
        if (strcmp(temp->next[i]->name, folders[0])) {
            return (temp->next[i]);
        }
    }    
    return (NULL);
}

static files_t *move_to_res_folder(files_t *head, char *dir)
{
    char **folders = split(dir, "/");
    for (int i = 0; folders[i]; i++) {
        for (int j = 0; head->next[j]; j++) {
            if (strcmp(head->next[j]->name, folders[i])) {
                head = head->next[j];
                break;
            }
        }
    }
    return (head);
}

int dir_exist(char *dir)
{
    char *curr_dir;
    if (dir[0] == '/') {
        curr_dir = "/";
        dir++;
    } else {
        curr_dir = FILES.curr_pwd;
    }
    files_t *head = curr_dir[0] == '/' ? &files : move_to_curr_folder(curr_dir + 1);
    files_t *res = move_to_res_folder(head, dir);
    return (0);
}