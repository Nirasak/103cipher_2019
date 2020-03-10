/*
** EPITECH PROJECT, 2019
** matrix_double.c
** File description:
** matrix_double
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"

void print_matrix_double(double **matrix, int cols)
{
    int i = 0;

    for (int j = 0; matrix[j] != NULL; j++) {
        for (i = 0; i < cols - 1; i++)
            printf("%.3f\t", matrix[j][i]);
        printf("%.3f", matrix[j][i]);
        printf("\n");
    }
    printf("\n");
}

double *set_line_matrix_double(double *m, char *key, int *x, int size)
{
    for (int i = 0; i < size; i++) {
        if (key[*x] != '\0') {
            m[i] = key[*x];
            (*x)++;
        } else
            m[i] = 0;
    }
    return (m);
}

double **square_matrix_double(char *key)
{
    int size = ROUND(sqrt((double)strlen(key)));
    double **matrix = malloc(sizeof(double *) * (size + 1));
    int x = 0;

    if (matrix == NULL)
        return (NULL);
    for (int i = 0; i < size; i++) {
        matrix[i] = malloc(sizeof(double) * (size + 1));
        if (matrix[i] == NULL)
            return (NULL);
        matrix[i] = set_line_matrix_double(matrix[i], key, &x, size);
    }
    matrix[size] = NULL;
    return (matrix);
}

double *set_line_msg_matrix_double(double *matrix, char *msg, int *x, int size)
{
    int j = 0;
    int a = 0;
    int nb = 0;

    for (int i = 0; i < size; i++) {
        for (; msg[j] != '\0' && a < *x; j++)
            if (msg[j] == ' ')
                a++;
        if (msg[j] == '\0' && i == 0)
            return (NULL);
        nb = atof(&msg[j]);
        matrix[i] = nb;
        (*x)++;
    }
    return (matrix);
}

double **get_matrix_msg_double(char *msg, char *key)
{
    int size = ROUND(sqrt((double)strlen(key)));
    int len = ROUND((double)strlen(msg) / (double)size);
    double **matrix = malloc(sizeof(double *) * (len + 1));
    int x = 0;

    if (matrix == NULL)
        return (NULL);
    for (int i = 0; i < len; i++) {
        matrix[i] = malloc(sizeof(double) * (size + 1));
        if (matrix[i] == NULL)
            return (NULL);
        matrix[i] = set_line_msg_matrix_double(matrix[i], msg, &x, size);
        if (matrix[i] == NULL)
            break;
    }
    matrix[len] = NULL;
    return (matrix);
}
