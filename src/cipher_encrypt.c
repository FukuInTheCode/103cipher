/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int convert_str(char *str, double *str_arr)
{
    double a = 0.;

    for (int i = 0; str[i]; i++) {
        a = (unsigned char)str[i];
        str_arr[i] = a;
    }
    return 0;
}

static int create_key_matrix(my_matrix_t *key_m, char *key)
{
    size_t root = (size_t)floor(sqrt(strlen(key)));
    double key_arr[strlen(key)];

    root += (pow(root, 2) != strlen(key));
    convert_str(key, key_arr);
    my_matrix_create(root, root, 1, key_m);
    my_matrix_fill_from_array(key_m, key_arr, strlen(key));
    return 0;
}

static int create_mess_matrix(my_matrix_t *mess_m, char *mess, uint32_t n)
{
    double mess_arr[strlen(mess)];
    uint32_t m = strlen(mess) / n + 1;

    convert_str(mess, mess_arr);
    my_matrix_create(m, n, 1, mess_m);
    my_matrix_fill_from_array(mess_m, mess_arr, strlen(mess));
    return 0;
}

static int print_matrices(my_matrix_t *key_m, my_matrix_t *result)
{
    printf("Key matrix:\n");
    for (int i = 0; i < key_m->m; i++) {
        for (int j = 0; j < key_m->n; j++)
            printf(j != key_m->n - 1 ? "%.0lf\t" : "%.0lf",
                key_m->arr[i][j]);
        printf("\n");
    }
    printf("\nEncrypted message:\n");
    for (int i = 0; i < result->m; i++)
        for (int j = 0; j < result->n; j++)
            printf((j != result->n - 1 || i != result->m - 1)
                ? "%.0lf " : "%.0lf", result->arr[i][j]);
    printf("\n");
    return 0;
}

int cipher_encrypt(char *message, char *key)
{
    my_matrix_t key_m = {0, 0, NULL};
    my_matrix_t mess_m = {0, 0, NULL};
    my_matrix_t result = {0, 0, NULL};

    create_key_matrix(&key_m, key);
    create_mess_matrix(&mess_m, message, key_m.n);
    my_matrix_product(&result, 2, &mess_m, &key_m);
    print_matrices(&key_m, &result);
    my_matrix_free(3, &key_m, &mess_m, &result);
    return 0;
}
