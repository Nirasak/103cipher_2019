/*
** EPITECH PROJECT, 2019
** decryption.c
** File description:
** decryption
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int det_matrix_2_2(int **matrix)
{
    int det = 0;

    det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    return (det);
}

double **inv_matrix_2_2(char *str, int det)
{
    double **matrix = square_matrix_double(str);
    double x = 1 * matrix[1][1] / det;

    matrix[0][1] = 1 * -matrix[0][1] / det;
    matrix[1][0] = 1 * -matrix[1][0] / det;
    matrix[1][1] = 1 * matrix[0][0] / det;
    matrix[0][0] = x;
    return (matrix);
}

int decryption_2(char **av)
{
    int **matrix_key = square_matrix(av[2]);
    double **inv_matrix_key = NULL;
    double **matrix_msg = get_matrix_msg_double(av[1], av[2]);
    double **matrix_res = create_matrix_double(av[1], av[2]);
    int det = det_matrix_2_2(matrix_key);

    if (det == 0 || matrix_msg == NULL ||
        matrix_res == NULL || matrix_key == NULL)
        return (84);
    inv_matrix_key = inv_matrix_2_2(av[2], det);
    printf("Key matrix:\n");
    print_matrix_double(inv_matrix_key, 2);
    mult_matrix_double(matrix_res, matrix_msg, inv_matrix_key, 2);
    printf("Encrypted message:\n");
    for (int j = 0; matrix_msg[j] != NULL; j++)
        print_msg_double(matrix_res[j], 2);
    printf("\n");
    return (0);
}

int decryption_3(char **av)
{
    double **matrix_key = square_matrix_double(av[2]);
    double **inv_matrix_key = NULL;
    double **matrix_msg = get_matrix_msg_double(av[1], av[2]);
    double **matrix_res = create_matrix_double(av[1], av[2]);
    int det = det_matrix_3_3(matrix_key);

    if (det == 0 || matrix_key == NULL ||
        matrix_msg == NULL || matrix_res == NULL)
        return (84);
    inv_matrix_key = inv_matrix_3_3(av[2], det, matrix_key);
    printf("Key matrix:\n");
    print_matrix_double(inv_matrix_key, 3);
    mult_matrix_double(matrix_res, matrix_msg, inv_matrix_key, 3);
    printf("Encrypted message:\n");
    for (int j = 0; matrix_msg[j] != NULL; j++)
        print_msg_double(matrix_res[j], 3);
    printf("\n");
    return (0);
}
