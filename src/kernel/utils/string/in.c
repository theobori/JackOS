int in(char c, const char *str)
{
    for (int i = 0; str[i]; i++) {
        if (c == str[i]) {
            return (1);
        }
    }
    return (0);
}