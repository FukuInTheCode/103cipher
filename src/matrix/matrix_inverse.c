/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int my_matrix_inverse(my_matrix_t *a, my_matrix_t *result)
{
    double det;
    my_matrix_t adjoint = {0, 0, NULL};

    if (a->m != a->n) {
        fprintf(stderr, "Matrix is not a square matrix!");
        return 84;
    }
    det = my_matrix_det(a);
    if (det == 0) {
        fprintf(stderr, "A is not inversible!\n");
        my_matrix_create(a->m, a->n, 1, result);
        return 84;
    }
    my_matrix_adjugate(a, &adjoint);
    my_matrix_multiplybyscalar(&adjoint, 1 / det, result);
    my_matrix_free(1, &adjoint);
    return 0;
}

int my_matrix_inverse_2(my_matrix_t *a)
{
    my_matrix_t cpy = {0, 0, NULL};

    my_matrix_copy(a, &cpy);
    my_matrix_inverse(&cpy, a);
    my_matrix_free(1, &cpy);
    return 0;
}
