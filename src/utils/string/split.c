#include "split.h"

/**
 * @brief count the nb of words that are in a string
 * 
 * @param str : the string to count
 * @param sep : the separator
 * @return int : the nb of words
 */
size_t count_nb_words(const char *str, const char *sep)
{
    size_t nb_words = 0;
    int last_char_sep = 1;

    for (size_t i = 0; str[i]; i++) {
        int is_in = in(str[i], sep);
        if (last_char_sep && !is_in) {
            nb_words++;
            last_char_sep = 0;
        } else if (is_in) {
            last_char_sep = 1;
        }
    }
    return (nb_words);
}

/**
 * @brief function that split a string into an array of strings
 * 
 * @param str : the string to split
 * @param sep : the separators
 * @return char** : the array of strings
 */
char **split(const char *str, const char *sep)
{
    const size_t nb_words = count_nb_words(str, sep);
    char **arr = malloc(sizeof(char *) * (nb_words + 1));
    size_t buff_id = 0;
    int empty_buf = 1;
    size_t arr_id = 0;

    for (size_t i = 0; str[i]; i++) {
        int is_sep = in(str[i], sep);
        if (!is_sep && empty_buf) {
            empty_buf = 0;
            buff_id = i;
        } else if (is_sep && !empty_buf) {
            arr[arr_id++] = strndup(str + buff_id, i - buff_id);
            empty_buf = 1;
        }
    }
    if (!empty_buf)
        arr[arr_id++] = strndup(str + buff_id, strlen(str) - buff_id);
    arr[arr_id] = NULL;
    return (arr);
}
