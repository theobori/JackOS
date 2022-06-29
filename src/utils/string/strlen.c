#include "strlen.h"

/**
 * @brief 
 * 
 * simple strlen function that return the length of a string
 * 
 * @param s : the string to be measured
 * @return int : the length of the string
 */
size_t strlen(const char *s)
{
    size_t len = 0;

    for (; s[len]; len++);
    return (len);
}