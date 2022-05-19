#ifndef __FILE_SYSTEM_H__
    #define __FILE_SYSTEM_H__

/**
 *                      This is File System API, 
 * all functions that you need for file manipulation is here 
 * You only need to include this file in your project
 */

typedef struct file_system_s {
    int (*create)();
    void (*dump_dev)();
} file_system_t;

file_system_t FILES;

void init_file_system();

#endif