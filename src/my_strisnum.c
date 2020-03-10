/*
** EPITECH PROJECT, 2019
** my_strisnum
** File description:
** my strisnum
*/

#include "my.h"

bool my_strisnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
            return (false);
    return (true);
}
