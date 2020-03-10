/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdbool.h>

#define ROUND(x) (x == (int)(x) ? ((int)x) : ((int)(x + 1)))
#define ROUNDNB(x) (x >= (int)(x) + 0.5 ? ((int)x) : ((int)(x + 1)))
#define POS(x) ((x > 0) ? x : (x > -0.001 ? 0 : x))

int print_descr(char *file);
int **square_matrix(char *key);
int **get_matrix_msg(char *msg, char *key);
int **create_matrix(char *msg, char *key);
int **mult_matrix(int **m_res, int **m1, int **m2, int cols);
bool my_strisnum(char const *str);
int cipher(char **av);
int det_matrix_2_2(int **matrix);
double **inv_matrix_2_2(char *str, int det);
double **square_matrix_double(char *key);
int decryption_2(char **av);
int *set_line_matrix(int *matrix, char *key, int *x, int size);
void print_matrix_double(double **matrix, int cols);
double **get_matrix_msg_double(char *msg, char *key);
double **create_matrix_double(char *msg, char *key);
double **mult_matrix_double(double **m_res, double **m1, double **m2, int cols);
int decryption_3(char **av);
int det_matrix_3_3(double **m1);
double **inv_matrix_3_3(char *key, int det, double **m1);
double **square_matrix_transposed(double **m1);
void print_msg_double(double *matrix, int cols);
int decryption_1(char **av);

#endif
