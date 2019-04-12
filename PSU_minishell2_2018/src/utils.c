/*
** EPITECH PROJECT, 2019
** .
** File description:
** .
*/


#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putchar_err(char c)
{
    write(2, &c, 1);
}

void my_putstr(char *str)
{
    int	i;

    i = -1;
    while (str && str[++i] != '\0')
        my_putchar(str[i]);
}

void my_putstr_err(char *str)
{
    int i;

    i = -1;
    while (str && str[++i] != '\0')
        my_putchar_err(str[i]);
}

int count_list(t_list *tmp, t_list *env)
{
    int count;

    count = 0;
    while (tmp != env){
        ++count;
        tmp = tmp->next;
    }
    return (count);
}
