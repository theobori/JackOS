#include "setxkbmap.h"

/**
 * @brief function that sets the keyboard layout
 * 
 * @param args : the layout language to set
 */
void setxkbmap(char **args)
{
    char *lang = args[0];
    upper(lang);
    change_lang(lang);
}