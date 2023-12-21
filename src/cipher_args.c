/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int cipher_args(char **argv)
{
    char *end_ptr = NULL;
    long flag = strtol(argv[3], &end_ptr, 10);

    if (end_ptr != argv[3] + strlen(argv[3]))
        return 84;
    if (flag == 0)
        return cipher_encrypt(argv[1], argv[2]);
    if (flag == 1)
        return cipher_decrypt(argv[1], argv[2]);
    return 84;
}
