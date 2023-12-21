/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int my_matrix_fill_from_array(my_matrix_t *a, double *arr, uint32_t arr_size)
{
    if (a->m == 0 || a->n == 0)
        return 84;
    for (uint32_t i = 0; i < arr_size; i++) {
        if (i + 1 > a->m * a->n)
            break;
        my_matrix_set(a, i / a->n, i % a->n, arr[i]);
    }
    return 0;
}
