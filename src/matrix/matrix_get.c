/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

double *my_matrix_getrow(my_matrix_t *a, uint32_t i)
{
    return a->arr[i];
}

int my_matrix_getcolumn(my_matrix_t *a, uint32_t n, double result[])
{
    for (uint32_t i = 0; i < a->m; i++)
        result[i] = a->arr[i][n];
    return 0;
}

int my_matrix_getsubmatrix(my_matrix_t *a, uint32_t const m,
    uint32_t const n, my_matrix_t *result)
{
    uint32_t my_var[] = {0, 0, 0};

    my_matrix_create(a->m - 1, a->n - 1, 1, result);
    for (uint32_t i = 0; i < a->m; i++) {
        if (i == m)
            continue;
        my_var[0] = 0;
        for (my_var[1] = 0; my_var[1] < a->n && my_var[1] < n; my_var[1]++) {
            result->arr[my_var[2]][my_var[0]] = a->arr[i][my_var[1]];
            my_var[0]++;
        }
        my_var[1]++;
        for (; my_var[1] < a->n; my_var[1]++) {
            result->arr[my_var[2]][my_var[0]] = a->arr[i][my_var[1]];
            my_var[0]++;
        }
        my_var[2]++;
    }
    return 0;
}
