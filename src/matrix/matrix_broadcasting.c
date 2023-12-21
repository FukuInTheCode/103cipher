/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int my_matrix_broadcasting(my_matrix_t *a, uint32_t m,
    uint32_t n, my_matrix_t *result)
{
    if (a->m > 1 && m > a->m)
        m = a->m;
    if (a->n > 1 && n > a->n)
        n = a->n;
    my_matrix_create(m, n, 1, result);
    if (a->m == 1 && a->n == 1)
        return my_matrix_addscalar_2(result, a->arr[0][0]);
    if (a->m == 1 && a->n != 1)
        for (uint32_t i = 0; i < a->n; i++)
            my_matrix_setcol(result, i, a->arr[0][i]);
    if (a->n == 1 && a->m != 1)
        for (uint32_t i = 0; i < a->m; i++)
            my_matrix_setrow(result, i, a->arr[i][0]);
    if (a->m != 1 && a->n != 1)
        my_matrix_copy(a, result);
    return 0;
}

int my_matrix_broadcasting_2(my_matrix_t *a, uint32_t m, uint32_t n)
{
    my_matrix_t cpy = {0, 0, NULL};

    my_matrix_copy(a, &cpy);
    my_matrix_broadcasting(&cpy, m, n, a);
    return my_matrix_free(1, &cpy);
}
