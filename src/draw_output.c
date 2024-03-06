/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** draw the main output
*/

#include "lib/include/my_lib.h"
#include "../include/my_navy.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void draw_boat(my_boats_t *my_boats, int i, int y)
{
    if (my_boats->map[i][y] == 8)
        my_putchar('o');
    if (my_boats->map[i][y] == 9)
        my_putchar('x');
    if ((my_boats->map[i][y] != 0) && (my_boats->map[i][y] < 8))
        my_putnbr(my_boats->map[i][y]);
    if (my_boats->map[i][y] == 0)
        my_putchar('.');
    if (y < 7)
        my_putchar(' ');
}

int draw_my_map(my_boats_t *my_boats, int i, int y)
{
    if ((my_boats->mapmine[i][y] == 0))
        my_putchar('.');
    if (my_boats->mapmine[i][y] == 1)
        my_putchar('o');
    if (my_boats->mapmine[i][y] == 2)
        my_putchar('x');
    if (y < 7)
        my_putchar(' ');
}

int drawmap(my_boats_t *my_boats)
{
    my_putstr("my navy:\n |A B C D E F G H\n-+---------------");
    for (int i = 0; i != 8; i ++) {
        my_putchar('\n');
        my_putnbr(i + 1);
        my_putchar('|');
        for (int y = 0; y != 8; y ++) {
            draw_boat(my_boats, i, y);
        }
    }
    my_putstr("\n\nenemy navy:\n |A B C D E F G H\n-+---------------");
    for (int i = 0; i != 8; i ++) {
        my_putchar('\n');
        my_putnbr(i + 1);
        my_putchar('|');
        for (int y = 0; y != 8; y ++) {
            draw_my_map(my_boats, i, y);
        }
    }
    return 0;
}
