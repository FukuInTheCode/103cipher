/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int my_matrix_setcol(my_matrix_t *a, uint32_t const n, double x)
{
    if (n >= a->n)
        return 84;
    for (uint32_t i = 0; i < a->m; i++)
        a->arr[i][n] = x;
    return 0;
}
