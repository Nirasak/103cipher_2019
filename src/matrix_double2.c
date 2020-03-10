/*
** EPITECH PROJECT, 2019
** matrix_double2.c
** File description:
** matrix double
*/

#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void print_msg_double(double *matrix, int cols)
{
    for (int i = 0; i < cols; i++)
        if ((int) roundf(matrix[i]) != 0)
            printf("%c", (int) roundf(matrix[i]));
}

double **create_matrix_double(char *msg, char *key)
{
    int size = ROUND(sqrt((double)strlen(key)));
    int len = ROUND((double)strlen(msg) / (double)size);
    double **matrix = malloc(sizeof(double *) * (len + 1));

    if (matrix == NULL)
        return (NULL);
    for (int j = 0; j < len; j++) {
        matrix[j] = malloc(sizeof(double) * (size + 1));
        if (matrix[j] == NULL)
            return (NULL);
        for (int i = 0; i < size; i++)
            matrix[j][i] = 0;
    }
    matrix[len] = NULL;
    return (matrix);
}
