/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int identity(my_matrix_t *a)
{
    if (a->m != a->n)
        return 84;
    for (uint32_t i = 0; i < a->m; i++) {
        for (uint32_t j = 0; j < a->n; j++)
            my_matrix_set(a, i, j, 0);
    }
    for (uint32_t i = 0; i < a->m; i++)
        my_matrix_set(a, i, i, 1);
    return 0;
}

int my_matrix_identity(uint32_t const count, ...)
{
    va_list args;
    my_matrix_t *a = NULL;

    va_start(args, count);
    for (uint32_t i = 0; i < count; i++) {
        a = va_arg(args, my_matrix_t *);
        identity(a);
    }
    va_end(args);
    return 0;
}
