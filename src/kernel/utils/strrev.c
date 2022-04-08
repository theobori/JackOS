#include "strrev.h"

/**
 * @brief 
 * 
 * simple strrev function that reverse a string
 * 
 * @param s : the string to be reversed
 */
void strrev(char *s) {
    int len_s = strlen(s);
    char tmp = 0;
    for (int i = 0; i < len_s / 2; i++) {
        tmp = s[i];
        s[i] = s[len_s - i - 1];
        s[len_s - i - 1] = tmp;
    }
}