#include "ping.h"

/**
 * @brief Just a ping pong command
 * 
 * @param args : arguments
 * @return int : status code
 */
int ping_command(char **args)
{
    tty_newline(0, 0);
    if (args[1]) {
        int repeat = atoi(args[1]);
        for (int i = 0; i < repeat; i++) {
            if (i)
                tty_newline(0, 0);
            tty_add_buff_str("PONG");
        }
    } else {
        tty_add_buff_str("PONG");
    }
    return (0);
}