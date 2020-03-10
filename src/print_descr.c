/*
** EPITECH PROJECT, 2019
** print_descr.c
** File description:
** print descr
*/

#include <stdio.h>
#include "my.h"

int print_descr(char *exe)
{
    printf(
        "USAGE\n    %s message key flag\n\n"
        "DESCRIPTION\n"
        "    message    a message, made of ASCII characteres\n"
        "    key        the encryption key, made of ASCII characters\n"
        "    flag       0 for the message to be encrypted, 1 to be decrypted\n",
        exe);
    return (0);
}
