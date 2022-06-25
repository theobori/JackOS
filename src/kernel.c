#include "kernel.h"

/**
 * @brief entry point of kernel
 * 
 */
void kmain()
{
    gdt_init();
    isr_install();
    init_timer(50);
    init_keyboard();
    init_mouse();
    shell_init();
    init_daniel();
    init_tty();
    init_file_system();

    TTY.update();
    FILES.create("/bin");
    FILES.create("/usr");
    FILES.create("/bin/ls");
    char **dirs = FILES.list_dirs("/");
    for (size_t i = 0; dirs[i]; i++) {
        GUI.printf(0, 100 + 20 * i, "(%s)", dirs[i]);
        if (strlen(dirs[i]) == 3) {
            GUI.draw_square(50, 50, 50, D_WHITE);
        }
    }
    dirs = FILES.list_dirs("/bin");
    for (size_t i = 0; dirs[i]; i++) {
        GUI.printf(0, 200 + 20 * i, "{%s}", dirs[i]);
    }
    test('$');
}
