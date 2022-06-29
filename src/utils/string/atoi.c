#include "atoi.h"

int atoi(const char *str)
{
    int res = 0;
    int sign = 1;
    
    if (str[0] == '-') {
        sign = -1;
        str++;
    }
    for (size_t i = 0; str[i]; i++) {
        res = res * 10 + str[i] - '0';
    }
    return (res * sign);
}