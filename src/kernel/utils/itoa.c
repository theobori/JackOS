#include "itoa.h"

/**
 * @brief 
 * 
 * simple itoa function that convert an integer to a string
 * 
 * @param n : the integer to be converted
 * @param str : the string to be filled
 */
void itoa(int n, char *str) {
    if (n < 0) {
        str[0] = '-';
        str++;
        n *= -1;
    }
    for (int i = 0; n > 0; i++) {
        str[i] = n % 10 + '0';
        n /= 10;
    }
}