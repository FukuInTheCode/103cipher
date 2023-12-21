/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int main(int argc, char **argv)
{
    if (argc == 2 && !strcmp(argv[1], "-h"))
        return cipher_help();
    if (argc == 4)
        return cipher_args(argv);
    return 84;
}
