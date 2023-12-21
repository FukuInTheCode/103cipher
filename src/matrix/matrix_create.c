/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int create(my_matrix_t *a, uint32_t m, uint32_t n)
{
    a->m = m;
    a->n = n;
    a->arr = calloc(m, sizeof(double *));
    if (!a->arr)
        return 84;
    for (uint32_t i = 0; i < m; i++) {
        a->arr[i] = calloc(n, sizeof(double));
        if (!a->arr[i])
            return 84 + my_matrix_free(1, a);
    }
    return 0;
}

int my_matrix_create(uint32_t m, uint32_t n, uint32_t const count, ...)
{
    va_list args;
    my_matrix_t *a_ptr = NULL;
    int error = 0;

    va_start(args, count);
    for (uint32_t i = 0; i < count; i++) {
        a_ptr = va_arg(args, my_matrix_t *);
        error |= create(a_ptr, m, n);
    }
    va_end(args);
    return error;
}
