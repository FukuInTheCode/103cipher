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

static int inside_loop(my_matrix_t *a, my_matrix_t *result,
    int is[2], int mn[2])
{
    uint32_t j2 = 0;
    uint32_t j = 0;

    if (is[0] == mn[0])
        return 0;
    for (; j < a->n && j < mn[1]; j++) {
        result->arr[is[1]][j2] = a->arr[is[0]][j];
        j2++;
    }
    for (j++ ; j < a->n; j++) {
        result->arr[is[1]][j2] = a->arr[is[0]][j];
        j2++;
    }
    is[1]++;
    return 0;
}

int my_matrix_getsubmatrix(my_matrix_t *a, uint32_t const m,
    uint32_t const n, my_matrix_t *result)
{
    uint32_t i2 = 0;

    my_matrix_create(a->m - 1, a->n - 1, 1, result);
    for (uint32_t i = 0; i < a->m; i++)
        inside_loop(a, result, (int [2]){i, i2}, (int [2]){m, n});
    return 0;
}
