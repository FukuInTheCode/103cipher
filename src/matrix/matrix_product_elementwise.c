/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int multiplication_is_valid(va_list args, uint32_t const count)
{
    my_matrix_t *a = va_arg(args, my_matrix_t *);
    uint32_t b_m = a->m;
    uint32_t b_n = a->n;

    for (uint32_t i = 0; i < count - 1; i++) {
        a = va_arg(args, my_matrix_t *);
        if ((a->m != b_m && a->m != 1) || (a->n != b_n && a->n != 1))
            return false;
    }
    return true;
}

static int multiply(my_matrix_t *result, my_matrix_t *a)
{
    my_matrix_t tmp = {0, 0, NULL};

    my_matrix_broadcasting(a, result->m, result->n, &tmp);
    for (uint32_t i = 0; i < result->m; i++)
        for (uint32_t j = 0; j < result->n; j++)
            result->arr[i][j] *= tmp.arr[i][j];
    my_matrix_free(1, tmp);
    return 0;
}

int my_matrix_product_elementwise(my_matrix_t *result,
    uint32_t const count, ...)
{
    va_list args;
    va_list args_copy;
    my_matrix_t *a = NULL;

    va_copy(args_copy, args);
    va_start(args_copy, count);
    if (!multiplication_is_valid(args_copy, count)) {
        va_end(args_copy);
        return 84;
    }
    va_end(args_copy);
    va_start(args, count);
    a = va_arg(args, my_matrix_t *);
    my_matrix_copy(a, result);
    for (uint32_t i = 0; i++ < (count - 1); a = va_arg(args, my_matrix_t *))
        multiply(result, a);
    va_end(args);
    return 0;
}
