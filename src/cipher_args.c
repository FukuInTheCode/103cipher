/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int cipher_args(char **argv)
{
    // detect flag and redirect to associated function
    cipher_encrypt(argv[1], argv[2]);
    return 84;
}
