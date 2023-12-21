/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <unistd.h>
    #include <stdint.h>
    #include <time.h>
    #include <limits.h>
    #include <stdarg.h>
    #include <errno.h>
    #include <math.h>
    #include <stdlib.h>

    #include <criterion/criterion.h>
    #include <criterion/redirect.h>

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Config.h>
    #include <SFML/GPUPreference.h>
    #include <SFML/Network.h>
    #include <SFML/OpenGL.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>

typedef struct {
    int m;
    int n;
    double **arr;
} my_matrix_t;

int cipher_help(void);
int cipher_args(char **);
int cipher_encrypt(char *, char *);
int cipher_decrypt(char *, char *);

int my_matrix_create(uint32_t, uint32_t, uint32_t, ...);
int my_matrix_free(uint32_t, ...);
double my_matrix_det(my_matrix_t *);
double *my_matrix_getrow(my_matrix_t *, uint32_t);
int my_matrix_getcolumn(my_matrix_t *, uint32_t, double *);
int my_matrix_inverse(my_matrix_t *, my_matrix_t *);
int my_matrix_inverse_2(my_matrix_t *);
int my_matrix_fill_from_array(my_matrix_t *, double *, uint32_t);
int my_matrix_product(my_matrix_t *, uint32_t, ...);
void my_matrix_getsubmatrix(my_matrix_t *, uint32_t const, uint32_t const,
    my_matrix_t *);
int my_matrix_adjugate(my_matrix_t *, my_matrix_t *);
int my_matrix_copy(my_matrix_t *, my_matrix_t *);
int my_matrix_set(my_matrix_t *, uint32_t const, uint32_t const, double);
int my_matrix_setcol(my_matrix_t *, uint32_t const, double);
int my_matrix_setrow(my_matrix_t *, uint32_t const, double);
double my_dot_product(double *, double *, unsigned);
int my_matrix_multiplybyscalar(my_matrix_t *, double, my_matrix_t *);
int my_matrix_identity(uint32_t const, ...);
int my_matrix_broadcasting(my_matrix_t *, uint32_t, uint32_t, my_matrix_t *);
int my_matrix_addscalar_2(my_matrix_t *, double);

#endif
