#include "join.h"

char *join(char **arr, char *sep)
{
    size_t sep_len = strlen(sep);
    size_t arr_full_len = 0;
    size_t arr_len = 0;
    for (size_t i = 0; arr[i]; i++) {
        arr_full_len += strlen(arr[i]);
        arr_len++;
    }
    size_t malloc_len = arr_full_len + sep_len * (arr_len - 1) + 1;
    char *res = malloc(sizeof(char) * malloc_len);
    memset(res, 0, malloc_len);
    for (size_t i = 0; arr[i]; i++) {
        strcat(res, arr[i]);
        if (arr[i + 1]) {
            strcat(res, sep);
        }
    }
    return (res);
}