/*
** EPITECH PROJECT, 2019
** .
** File description:
** .
*/


#include "my.h"

int my_getnext(int nbr, int i, int nega, char *str)
{
    while (str[i] >= '0' && str[i] <= '9'){
        nbr = (nbr * 10);
        nbr = nbr + (str[i] - '0');
        if (nbr < 0)
            if (nbr != -2147483648 || nega == 1)
                return (0);
        i += 1;
    }
    return (nbr);
}

int my_getnbr(char *str)
{
    int nbr;
    int i;
    int nega;

    nbr = 0;
    i = 0;
    nega = 1;
    while (str[i] != '\0' && (str[i] == '-' || str[i] == '+')){
        if (str[i] == '-')
            nega = nega * -1;
        i += 1;
    }
    nbr = my_getnext(nbr, i, nega, str);
    return (nbr * nega);
}
