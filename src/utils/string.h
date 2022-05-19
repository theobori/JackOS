#ifndef __STRING_H__
    #define __STRING_H__

    #include <stddef.h> 

/*
**          String Functions public API
** this is all string managements function that you can use.
** you must include only this file to use these functions.
*/

int strlen(const char *str);
void strrev(char *s);
void itoa(int n, char *str);
int strcmp(const char *s1, const char *s2);
void upper(char *str);
char **split(const char *str, const char *sep);
int in(char c, const char *str);
void strcpy(char *dest, const char *src);
void strncpy(char *dest, const char *src, size_t n);
void trim(char *str, char *sep);
char *strdup(const char *str);
char *strndup(const char *str, size_t n);
void trim(char *str, char *sep);
int atoi(const char *str);

#endif