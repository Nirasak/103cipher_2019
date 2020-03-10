/*
** EPITECH PROJECT, 2019
** matrix.c
** File description:
** matrix
*/

#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"

int *set_line_matrix(int *matrix, char *key, int *x, int size)
{
    for (int i = 0; i < size; i++) {
        if (key[*x] != '\0') {
            matrix[i] = key[*x];
            (*x)++;
        } else
            matrix[i] = 0;
    }
    return (matrix);
}

int **square_matrix(char *key)
{
    int size = ROUND(sqrt((double)strlen(key)));
    int **matrix = malloc(sizeof(int *) * (size + 1));
    int x = 0;

    if (matrix == NULL)
        return (NULL);
    for (int i = 0; i < size; i++) {
        matrix[i] = malloc(sizeof(int) * (size + 1));
        if (matrix[i] == NULL)
            return (NULL);
        matrix[i] = set_line_matrix(matrix[i], key, &x, size);
    }
    matrix[size] = NULL;
    return (matrix);
}
