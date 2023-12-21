/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int my_matrix_set(my_matrix_t *a, uint32_t const m,
    uint32_t const n, double const  x)
{
    if (n > a->n || m > a->m)
        return 0;
    a->arr[m][n] = x;
    return 0;
}
