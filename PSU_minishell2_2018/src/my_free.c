/*
** EPITECH PROJECT, 2019
** .
** File description:
** .
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void my_free(char **tab)
{
    int i;

    i = 0;
    if (tab != NULL){
        while (tab[i] != '\0')
            free(tab[i++]);
        free(tab);
    }
}
