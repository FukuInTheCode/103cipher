/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int my_matrix_multiplybyscalar(my_matrix_t *a, double scalar,
    my_matrix_t *result)
{
    my_matrix_copy(a, result);
    for (uint32_t i = 0; i < a->m; i++)
        for (uint32_t j = 0; j < a->n; j++)
            result->arr[i][j] *= scalar;
    return 0;
}

int my_matrix_addscalar(my_matrix_t *a, double scalar, my_matrix_t *result)
{
    my_matrix_copy(a, result);
    for (uint32_t i = 0; i < a->m; i++)
        for (uint32_t j = 0; j < a->n; j++)
            result->arr[i][j] += scalar;
    return 0;
}

int my_matrix_addscalar_2(my_matrix_t *a, double scalar)
{
    my_matrix_t cpy = {0, 0, NULL};

    my_matrix_copy(a, &cpy);
    my_matrix_addscalar(&cpy, scalar, a);
    my_matrix_free(1, &cpy);
    return 0;
}

int my_matrix_multiplybyscalar_2(my_matrix_t *a, double scalar)
{
    my_matrix_t cpy = {0, 0, NULL};

    my_matrix_copy(a, &cpy);
    my_matrix_multiplybyscalar(&cpy, scalar, a);
    my_matrix_free(1, &cpy);
    return 0;
}
