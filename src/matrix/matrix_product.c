/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static bool product_is_valid(va_list args, uint32_t const count)
{
    my_matrix_t *a = va_arg(args, my_matrix_t *);
    uint32_t inside = a->n;

    for (uint32_t i = 0; i < (count - 1); i++) {
        a = va_arg(args, my_matrix_t *);
        if (a->m != inside)
            return false;
        inside = a->n;
    }
    return true;
}

static int my_product(my_matrix_t *a, my_matrix_t *b, my_matrix_t *result)
{
    double *row = NULL;
    double col[b->m];

    my_matrix_create(a->m, b->n, 1, result);
    for (uint32_t i = 0; i < result->m; i++) {
        row = my_matrix_getrow(a, i);
        for (uint32_t j = 0; j < result->n; j++) {
            my_matrix_getcolumn(b, j, col);
            my_matrix_set(result, i, j, my_dot_product(row, col, a->n));
        }
    }
    return 0;
}

static int verify_product(va_list args_copy, uint32_t const count)
{
    if (!product_is_valid(args_copy, count)) {
        va_end(args_copy);
        return 84;
    }
    va_end(args_copy);
    return 0;
}

int my_matrix_product(my_matrix_t *result, uint32_t const count, ...)
{
    va_list args;
    my_matrix_t *a = NULL;
    my_matrix_t *b = NULL;
    my_matrix_t copy = {0, 0, NULL};
    va_list args_copy;

    va_start(args, count);
    va_copy(args_copy, args);
    if (verify_product(args_copy, count))
        return 84;
    a = va_arg(args, my_matrix_t *);
    my_matrix_copy(a, &copy);
    for (uint32_t i = 0; i < (count - 1); i++) {
        b = va_arg(args, my_matrix_t *);
        my_product(&copy, b, result);
        my_matrix_copy(result, &copy);
    }
    va_end(args);
    return my_matrix_free(1, &copy);
}
