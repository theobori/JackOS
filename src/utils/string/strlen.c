#include "strlen.h"

/**
 * @brief 
 * 
 * simple strlen function that return the length of a string
 * 
 * @param s : the string to be measured
 * @return int : the length of the string
 */
int strlen(const char *s)
{
    int len = 0;

    for (; s[len]; len++);
    return (len);
}