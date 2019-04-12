/*
** EPITECH PROJECT, 2019
** .
** File description:
** .
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

char *pathornotpath(char *path)
{
    if (path == NULL)
        return ("/bin:/sbin:/usr/bin:/usr/sbin");
    return (path);
}

int my_builtin(char **command, t_list *env)
{
    char (*redirection[5])(char **, t_list *);
    char **builtin;
    int i;

    if ((builtin = malloc(sizeof(char *) * 5)) == NULL)
        my_puterror("Problem with a memory allocation(5)");
    builtin[0] = "exit";
    builtin[1] = "cd";
    builtin[2] = "env";
    builtin[3] = "unsetenv";
    builtin[4] = "setenv";
    redirection[0] = my_builtin_exit;
    redirection[1] = my_builtin_cd;
    redirection[2] = my_builtin_env;
    redirection[3] = my_builtin_unsetenv;
    redirection[4] = my_builtin_setenv;
    i = -1;
    while (++i < 5 && !my_strcmp(command[0], builtin[i], 0));
    free(builtin);
    return ((i == 5) ? (42) : redirection[i](command, env));
}

char check_command(char **command, t_list *env)
{
    if (command[0] == NULL || command == NULL)
        return (0);
    if ((my_builtin(command, env)) == 42)
        my_execve(command, env, pathornotpath(search_env(env, "PATH")));
    return (0);
}
