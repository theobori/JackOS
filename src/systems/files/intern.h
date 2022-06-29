#ifndef __FILE_INTERN_H__
    #define __FILE_INTERN_H__

    #include "../files.h"

    #define BLOCK_SIZE 2048
    #define MAX_FILES 64
    
    #define NAME_SIZE 128
    #define HEADER_SIZE (NAMESIZE + 8)     // 8 is for new block location

files_t files;

#endif