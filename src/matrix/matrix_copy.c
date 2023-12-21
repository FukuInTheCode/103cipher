/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int my_matrix_copy(my_matrix_t *a, my_matrix_t *copy)
{
    my_matrix_create(a->m, a->n, 1, copy);
    for (uint32_t i = 0; i < a->m; i++)
        for (uint32_t j = 0; j < a->n; j++)
            my_matrix_set(copy, i, j, a->arr[i][j]);
    return 0;
}
