/*
** EPITECH PROJECT, 2019
** mult_matrix.c
** File description:
** mult matrix
*/

#include <stddef.h>
#include "my.h"

int mult_matrix2(int *m1, int **m2, int j)
{
    int res = 0;

    for (int i = 0; m2[i] != NULL; i++)
        res += m1[i] * m2[i][j];
    return (res);
}

int **mult_matrix(int **m_res, int **m1, int **m2, int cols)
{
    for (int j = 0; m1[j] != NULL; j++)
        for (int i = 0; i < cols; i++)
            m_res[j][i] = mult_matrix2(m1[j], m2, i);
    return (m_res);
}

double mult_matrix_double2(double *m1, double **m2, int j)
{
    double res = 0;

    for (int i = 0; m2[i] != NULL; i++)
        res += m1[i] * m2[i][j];
    return (res);
}

double **mult_matrix_double(double **m_res, double **m1, double **m2, int cols)
{
    int j = 0;

    for (; m1[j] != NULL; j++)
        for (int i = 0; i < cols; i++)
            m_res[j][i] = mult_matrix_double2(m1[j], m2, i);
    m_res[j] = NULL;
    return (m_res);
}
