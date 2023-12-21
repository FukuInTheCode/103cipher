/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

double my_matrix_det(my_matrix_t *a)
{
    double det = 0;
    double sign = 1;
    my_matrix_t submatrix = {0, 0, NULL};

    if (a->m != a->n) {
        fprintf(stderr, "Matrix is not square matrix!");
        exit(84);
    }
    if (a->m == 1)
        return a->arr[0][0];
    for (uint32_t i = 0; i < a->n; i++) {
        sign = pow(-1.0, i);
        my_matrix_getsubmatrix(a, 0, i, &submatrix);
        det += sign * a->arr[0][i] * my_matrix_det(&submatrix);
        my_matrix_free(1, &submatrix);
    }
    return det;
}
