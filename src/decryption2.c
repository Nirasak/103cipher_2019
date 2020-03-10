/*
** EPITECH PROJECT, 2019
** decryption2.c
** File description:
** decryption2
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"

double **square_matrix_transposed(double **m1)
{
    double **matrix = malloc(sizeof(double *) * 4);

    if (matrix == NULL)
        return (NULL);
    for (int i = 0; i < 3; i++) {
        matrix[i] = malloc(sizeof(double) * 4);
        if (matrix[i] == NULL)
            return (NULL);
        for (int j = 0; j < 3; j++)
            matrix[i][j] = m1[j][i];
    }
    matrix[3] = NULL;
    return (matrix);
}

int det_matrix_3_3(double **m1)
{
    int det = 0;

    det = m1[0][0] * (m1[1][1] * m1[2][2] - m1[1][2] * m1[2][1]);
    det += m1[0][1] * -(m1[1][0] * m1[2][2] - m1[1][2] * m1[2][0]);
    det += m1[0][2] * (m1[1][0] * m1[2][1] - m1[1][1] * m1[2][0]);
    return (det);
}

double **inv_matrix_3_3(char *str, int det, double **m1)
{
    double **matrix = square_matrix_double(str);
    double **res = NULL;

    matrix[0][0] = POS(1 * (m1[1][1] * m1[2][2] - m1[1][2] * m1[2][1]) / det);
    matrix[0][1] = POS(1 * -(m1[1][0] * m1[2][2] - m1[1][2] * m1[2][0]) / det);
    matrix[0][2] = POS(1 * (m1[1][0] * m1[2][1] - m1[1][1] * m1[2][0]) / det);
    matrix[1][0] = POS(1 * -(m1[0][1] * m1[2][2] - m1[0][2] * m1[2][1]) / det);
    matrix[1][1] = POS(1 * (m1[0][0] * m1[2][2] - m1[0][2] * m1[2][0]) / det);
    matrix[1][2] = POS(1 * -(m1[0][0] * m1[2][1] - m1[0][1] * m1[2][0]) / det);
    matrix[2][0] = POS(1 * (m1[0][1] * m1[1][2] - m1[0][2] * m1[1][1]) / det);
    matrix[2][1] = POS(1 * -(m1[0][0] * m1[1][2] - m1[0][2] * m1[1][0]) / det);
    matrix[2][2] = POS(1 * (m1[0][0] * m1[1][1] - m1[0][1] * m1[1][0]) / det);
    res = square_matrix_transposed(matrix);
    return (res);
}

int decryption_1(char **av)
{
    double matrix = 0;
    double inv_matrix = 0;
    double **matrix_msg = get_matrix_msg_double(av[1], av[2]);

    if (strlen(av[2]) == 0 || matrix_msg == NULL)
        return (84);
    matrix = av[2][0];
    if (matrix == 0)
        return (84);
    inv_matrix = 1 / matrix;
    printf("Key matrix:\n%.3f\n\n", inv_matrix);
    printf("Encrypted message\n");
    for (size_t i = 0; matrix_msg[i] != NULL; i++)
        printf("%c", (int) roundf(matrix_msg[i][0] * inv_matrix));
    printf("\n");
    return (0);
}
