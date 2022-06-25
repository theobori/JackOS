#ifndef __FILE_SYSTEM_H__
    #define __FILE_SYSTEM_H__

/**
 *                      This is File System API, 
 * all functions that you need for file manipulation is here 
 * You only need to include this file in your project
 */

enum FILE_TYPE {
    FILE,
    FOLDER
};

typedef struct files_s {
    struct files_s **next;
    char *name;
    void *block;
    enum FILE_TYPE type;
} files_t;

typedef struct file_system_s {
    char *curr_pwd;
    int (*create)();
    char **(*list_dirs)(const char *);
    char *(*get_curr_pwd)();
    int (*change_dir)(char *path);
    int (*dir_exist)(char *dir);
    files_t *(*get_folder)(char *path);
} file_system_t;

file_system_t FILES;

void init_file_system();

#endif