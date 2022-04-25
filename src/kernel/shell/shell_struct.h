#ifndef __SHELL_STRUCT_H__
    #define __SHELL_STRUCT_H__

    #define MAX_LINE 256
    #define MAX_PROMPT 8

typedef struct shell_s {
    char prompt[MAX_PROMPT];
    char line[MAX_LINE];
    unsigned int line_size;
    unsigned int prompt_size;
    unsigned int y;
} shell_t;

shell_t shell;

#endif