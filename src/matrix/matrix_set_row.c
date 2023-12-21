/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int my_matrix_setrow(my_matrix_t *a, uint32_t const m, double x)
{
    if (m >= a->m)
        return 84;
    for (uint32_t i = 0; i < a->n; i++)
        a->arr[m][i] = x;
    return 0;
}
