/*
** EPITECH PROJECT, 2019
** cipher.c
** File description:
** cipher
*/

#include <math.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "my.h"

void print_matrix(int **matrix, int cols)
{
    int i = 0;

    for (int j = 0; matrix[j] != NULL; j++) {
        for (i = 0; i < cols - 1; i++)
            printf("%d\t", matrix[j][i]);
        printf("%d", matrix[j][i]);
        printf("\n");
    }
    printf("\n");
}

void print_msg(int *matrix, int *matrix2, int cols)
{
    for (int i = 0; i < cols; i++) {
        printf("%d", matrix[i]);
        if (matrix2 != NULL || i != (cols - 1))
            printf(" ");
        else
            printf("\n");
    }
}

int encryption(char **av)
{
    int **matrix_key = square_matrix(av[2]);
    int **matrix_msg = get_matrix_msg(av[1], av[2]);
    int **matrix_res = create_matrix(av[1], av[2]);

    if (matrix_key == NULL || matrix_msg == NULL || matrix_res == NULL)
        return (84);
    printf("Key matrix:\n");
    print_matrix(matrix_key, ROUND(sqrt((double)strlen(av[2]))));
    mult_matrix(
        matrix_res, matrix_msg, matrix_key, ROUND(sqrt((double)strlen(av[2]))));
    printf("Encrypted message:\n");
    for (int j = 0; matrix_res[j] != NULL; j++)
        print_msg(
            matrix_res[j], matrix_res[j + 1],
            ROUND(sqrt((double)strlen(av[2]))));
    return (0);
}

int decryption(char **av)
{
    if (strlen(av[2]) <= 1)
        return (decryption_1(av));
    if (strlen(av[2]) <= 4)
        return (decryption_2(av));
    if (strlen(av[2]) <= 9)
        return (decryption_3(av));
    return (84);
}

int cipher(char **av)
{
    if (strcmp(av[3], "0") == 0)
        return (encryption(av));
    if (strcmp(av[3], "1") == 0 && my_strisnum(av[1]) == true)
        return (decryption(av));
    return (84);
}
