#include "commands.h"

char *commands[] = {
    "ping",
    "pwd",
    "ls",
    "mkdir",
    "cd",
    "clear",
    "echo",
    "cat",
    "man",
    NULL
};

int (*commands_func[])(char **) = {
    &ping_command,
    &pwd_command,
    &ls_command,
    &mkdir_command,
    &cd_command,
    &clear_command,
    &echo_command,
    &cat_command,
    &man_command,
    NULL
};

/**
 * @brief delete the prompt from the line
 * 
 * @param command : command to purify
 * @return char* : purified command
 */
static const char *delete_prompt(const char *command)
{
    return (command + strlen(this.prompt));
}

/**
 * @brief Launch the command in arg
 * 
 * @param command : command to launch
 */
void launch_command(const char *command)
{
    char **words = split(delete_prompt(command), " ");

    for (size_t i = 0; commands[i]; i++) {
        if (strcmp(words[0], commands[i])) {
            commands_func[i](words);
            break;
        }
    }
}