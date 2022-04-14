/**
 * @brief function that converts a string to uppercase
 * 
 * @param str : the string to convert
 */
void upper(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
}