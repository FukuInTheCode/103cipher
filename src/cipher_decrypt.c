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
    int error = 0;

    root += (pow(root, 2) != strlen(key));
    convert_str(key, key_arr);
    my_matrix_create(root, root, 1, key_m);
    my_matrix_fill_from_array(key_m, key_arr, strlen(key));
    error |= my_matrix_inverse_2(key_m);
    return error;
}

static int convert_mess(char *mess, double *mess_arr)
{
    char *end_ptr = NULL;
    int k = 0;

    for (int i = 0; i < strlen(mess); i++) {
        if (!('0' <= mess[i] && mess[i] <= '9') && mess[i] != ' ')
            return 84;
        if (i != 0 && mess[i] != ' ')
            continue;
        mess_arr[k] = strtod(mess + i, &end_ptr);
        k++;
        if ('0' <= *end_ptr && *end_ptr <= '9')
            end_ptr++;
        if (*end_ptr != ' ' && *end_ptr != 0)
            return 84;
    }
    return 0;
}

static int create_mess_matrix(my_matrix_t *mess_m, char *mess, uint32_t n)
{
    double *mess_arr;
    int k = 1;

    for (int i = 0; mess[i]; i++)
        k += mess[i] == ' ';
    mess_arr = calloc(k, sizeof(double));
    if (!mess_arr || convert_mess(mess, mess_arr))
        return 84;
    my_matrix_create(k / n + 1, n, 1, mess_m);
    my_matrix_fill_from_array(mess_m, mess_arr, k);
    free(mess_arr);
    return 0;
}

static int print_matrices(my_matrix_t *key_m, my_matrix_t *result)
{
    char buf[1001] = {0};

    printf("Key matrix:\n");
    for (int i = 0; i < key_m->m; i++) {
        for (int j = 0; j < key_m->n; j++)
            printf("%lf\t", suppr_zero(key_m->arr[i][j]));
        printf("\n");
    }
    printf("\nDecrypted message:\n");
    for (int i = 0; i < result->m; i++) {
        for (int j = 0; j < result->n; j++) {
            sprintf(buf, "%lf\n", result->arr[i][j]);
            printf("%c", (char)atoi(buf));
            memset((void *)buf, 0, strlen(buf));
        }
    }
    printf("\n");
    return 0;
}

int cipher_decrypt(char *message, char *key)
{
    my_matrix_t key_m = {0, 0, NULL};
    my_matrix_t mess_m = {0, 0, NULL};
    my_matrix_t result = {0, 0, NULL};

    create_key_matrix(&key_m, key);
    if (create_mess_matrix(&mess_m, message, key_m.n))
        return 84;
    my_matrix_product(&result, 2, &mess_m, &key_m);
    print_matrices(&key_m, &result);
    my_matrix_free(3, &key_m, &mess_m, &result);
    return 0;
}
