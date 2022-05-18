#include "update.h"

static void callback(char c)
{
    if (!c) {
        return;
    }
    if (c == '\n') {
        tty_newline();
    } else if (c == '\b') {
        tty_delete_last_char();
    } else {
        tty_add_buff(c);
    }
    tty_display();
}

void update()
{
    get_char_pressed(&callback);
}