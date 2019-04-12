/*
** EPITECH PROJECT, 2019
** .
** File description:
** .
*/


#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int my_count(char *str, char c)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i] != '\0') {
        while (str[i] && (str[i] == c || str[i] == '\t'))
            i++;
        if (str[i])
            count++;
        if (str[i] != '\0')
            i++;
    }
    return (count);
}

int my_strlentab(const char *str, char c)
{
    int i;

    i = -1;
    while (str[++i] != '\0' && str[i] != c && str[i] != '\t');
    return (i);
}

char **my_str_to_wordtab(char *str, char c)
{
    int i = 0;
    word_t w;
    init(&w);

    if ((w.tab = malloc((my_count(str, c) + 1) * sizeof(*w.tab))) == NULL)
        my_puterror("Problem with a memory allocation(2)");
    while (str[i]){
        w.j = 0;
        while (str[i] && (str[i] == c || str[i] == ' ' || str[i] == '\t'))
            ++i;
        if ((w.tab[++w.z] = malloc((my_strlentab(&str[i], c) + 1)
            * sizeof(**w.tab))) == NULL)
            my_puterror("Problem with a memory allocation(3)");
        while (str[i] && str[i] != c && str[i] != ' ' && str[i] != '\t')
            w.tab[w.z][w.j++] = str[i++];
        w.tab[w.z][w.j] = '\0';
        while (str[i] && (str[i] == c || str[i] == ' ' || str[i] == '\t'))
            ++i;
    }
    w.tab[w.z + 1] = '\0';
    return (w.tab);
}

void init(word_t *word)
{
    word->z = -1;
    word->j;
}