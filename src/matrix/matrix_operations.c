/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int my_matrix_adjugate(my_matrix_t *a, my_matrix_t *result)
{
    my_matrix_t sub = {0, 0, NULL};
    double cofactor;

    if (a->m != a->n) {
        fprintf(stderr, "Matrix is not a square matrix!");
        exit(1);
    }
    if (a->m == 1)
        return my_matrix_identity(1, result);
    my_matrix_create(a->m, a->n, 1, result);
    for (uint32_t i = 0; i < result->m; i++) {
        for (uint32_t j = 0; j < result->n; j++){
            my_matrix_getsubmatrix(a, i, j, &sub);
            cofactor = pow(-1, i + j) * my_matrix_det(&sub);
            my_matrix_set(result, j, i, cofactor);
            my_matrix_free(1, &sub);
        }
    }
    return 0;
}
