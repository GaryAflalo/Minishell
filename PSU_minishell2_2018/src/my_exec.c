/*
** EPITECH PROJECT, 2019
** .
** File description:
** .
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char **check_alias(char **command)
{
    if (my_strcmp(command[0], "lc", 0))
        return (my_str_to_wordtab("ls --color", ' '));
    if (my_strcmp(command[0], "ll", 0))
        return (my_str_to_wordtab("ls -alF --color", ' '));
    if (my_strcmp(command[0], "ne", 0))
        return (my_str_to_wordtab("emacs -nw", ' '));
    if (my_strcmp(command[0], "la", 0))
        return (my_str_to_wordtab("ls -lA --color", ' '));
    if (my_strcmp(command[0], "clean", 0))
        return (my_str_to_wordtab("rm -f *~ ; -f *#", ' '));
    return (command);
}

char test_file(char opt, char opt2, char **command)
{
    if (opt != ' '){
        if (command[0][0] == opt && command[0][1] == opt2
            && (access(command[0], F_OK) != -1))
            return (0);
    }
    else if (opt == ' ')
        if (command[0][0] == opt2 && (access(command[0], F_OK) != -1))
            return (0);
    return (1);
}

char *recursive_execve(char **path, char **command, char **tabenv, int i)
{
    char *filename;

    filename = NULL;
    if (!test_file('.', '/', command)){
        if (((filename = command[0]) && (access(command[0], R_OK | X_OK) == -1))
            || (execve(filename, command, tabenv) == -1))
            return ("Permissions denied.");
    }
    else if (command[0][0] != '/')
        filename = my_strcat(path[i++], command[0], 1);
    else if (!test_file(' ', '/', command))
        if (((filename = command[0]) && (access(command[0], R_OK | X_OK) == -1))
            || (execve(filename, command, tabenv) == -1))
            return ("Permissions denied.");
    if (filename != NULL){
        execve(filename, command, tabenv);
        recursive_execve(path, command, tabenv, i);
    }
    else
        return (NULL);
    return (0);
}

void execve_error(char *error, char **command, char **tabenv)
{
    my_puterror_execve(error, command);
    my_free(command);
    my_free(tabenv);
    exit(EXIT_FAILURE);
}

char my_execve(char **command, t_list *env, char *path)
{
    char **tabenv = NULL;
    int status;
    pid_t pid;
    int i = 0;
    char *error = NULL;

    pid = fork();
    if (pid == -1)
        my_puterror("Impossible, error with pid");
    else if (pid == 0){
        tabenv = conv_list(env);
        error = recursive_execve(my_str_to_wordtab(path, ':'),
        check_alias(command), tabenv, i);
        execve_error(error, command, tabenv);
    }
    else
    if (wait(&status) == -1)
        my_puterror("Impossible to use wait\n");
    if (WTERMSIG(status) == 11)
        my_putstr("Segmentation fault (core dumped)\n");
    return (0);
}
