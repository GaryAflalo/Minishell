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

char *update_env_cd(t_list *env, char *change)
{
    char *buff;

    if (search_env(env, change) != NULL){
        if ((buff = malloc(sizeof(char *) * 128)) == NULL)
            my_puterror("Error with a memory allocation(5)");
        getcwd(buff, 128);
        env = update_env(env, my_strcat(my_strcat(change, "=", 0),
        buff, 0), change);
        free(buff);
    }
    return (NULL);
}

char *check_directory(t_list *env, char *command)
{
    char *dir;

    if (command == NULL || my_strcmp(command, " ", 0)
        || my_strcmp(command, "\t", 0) || my_strcmp(command, "\0", 0))
        dir = search_env(env, "HOME");
    else if (my_strcmp(command, "-", 0))
        dir = search_env(env, "OLDPWD");
    else if (my_strcmp(command, "~", 0))
        dir = search_env(env, "HOME");
    else
        dir = command;
    return (dir);
}

char my_builtin_cd(char **command, t_list *env)
{
    char *dir;

    if ((dir = check_directory(env, command[1])) == NULL)
        return (0);
    if (access(dir, F_OK) == -1)
        return (my_puterrorcd("No such file or directory.", dir));
    if (access(dir, R_OK) == -1)
        return (my_puterrorcd("Permission denied.", dir));
    update_env_cd(env, "OLDPWD");
    if (chdir(dir) == -1)
        return (my_puterrorcd("Not a directory.", dir));
    update_env_cd(env, "PWD");
    return (0);
}
