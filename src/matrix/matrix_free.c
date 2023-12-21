/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int my_free(my_matrix_t *a)
{
    for (uint32_t i = 0; i < a->m; i++) {
        free(a->arr[i]);
        a->arr[i] = NULL;
    }
    free(a->arr);
    a->arr = NULL;
    a->m = 0;
    a->n = 0;
    return 0;
}

static bool free_is_valid(my_matrix_t *a)
{
    return (a->m == 0 || a->n == 0 || a->arr == NULL) ? false : true;
}

int my_matrix_free(uint32_t const count, ...)
{
    va_list args;
    my_matrix_t *a_ptr = NULL;

    va_start(args, count);
    for (uint32_t i = 0; i < count; i++) {
        a_ptr = va_arg(args, my_matrix_t *);
        if (!free_is_valid(a_ptr))
            continue;
        my_free(a_ptr);
    }
    va_end(args);
    return 0;
}
