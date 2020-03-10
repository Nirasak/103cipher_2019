/*
** EPITECH PROJECT, 2019
** encryption.c
** File description:
** encryption
*/

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "my.h"

int **get_matrix_msg(char *msg, char *key)
{
    int size = ROUND(sqrt((double)strlen(key)));
    int len = ROUND((double)strlen(msg) / (double)size);
    int **matrix = malloc(sizeof(int *) * (len + 1));
    int x = 0;

    if (matrix == NULL)
        return (NULL);
    for (int i = 0; i < len; i++) {
        matrix[i] = malloc(sizeof(int) * (size + 1));
        if (matrix[i] == NULL)
            return (NULL);
        matrix[i] = set_line_matrix(matrix[i], msg, &x, size);
    }
    matrix[len] = NULL;
    return (matrix);
}

int **create_matrix(char *msg, char *key)
{
    int size = ROUND(sqrt((double)strlen(key)));
    int len = ROUND((double)strlen(msg) / (double)size);
    int **matrix = malloc(sizeof(int *) * (len + 1));

    if (matrix == NULL)
        return (NULL);
    for (int j = 0; j < len; j++) {
        matrix[j] = malloc(sizeof(int) * (size + 1));
        if (matrix[j] == NULL)
            return (NULL);
        for (int i = 0; i < size; i++)
            matrix[j][i] = 0;
    }
    matrix[len] = NULL;
    return (matrix);
}
