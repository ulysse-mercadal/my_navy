/*
** EPITECH PROJECT, 2024
** lib reworked
** File description:
** print an float
*/

#include "../include/my_lib.h"

int my_putfloat(float nbr, int presision)
{
    int before_coma;
    int after_coma;

    presision = my_pow(10, presision);
    before_coma = nbr;
    after_coma = (nbr * presision) - before_coma * presision;
    my_putnbr(before_coma);
    my_putchar('.');
    my_putnbr(after_coma);
    if (after_coma == 0)
        my_putchar('0');
    return 0;
}
