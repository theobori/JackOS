#include "split.h"

/**
 * @brief function that split a string into an array of strings
 * 
 * @param str : the string to split
 * @param sep : the separators
 * @return char** : the array of strings
 */
char **split(const char *str, const char *sep)
{
    char **arr = NULL;
    char *buf = malloc(sizeof(char) * (strlen(str) + 1));
    int empty_buf = 0;
    int buf_start = 0;
    int arr_i = 0;
    int is_sep = 0;

    strcpy(buf, str);
    for (int i = 0; buf[i]; i++) {
        is_sep = in(buf[i], sep);
        if (is_sep && !empty_buf) {
            buf[i] = '\0';
            arr[arr_i++] = &buf[buf_start];
            empty_buf = 1;
        } else if (!is_sep && empty_buf) {
            buf_start = i;
            empty_buf = 0;
        } else if (!is_sep && !empty_buf) {
            empty_buf = 0;
        }
    }
    if (!empty_buf)
        arr[arr_i++] = &buf[buf_start];
    return (arr);
}