/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** check is the boat is correct
*/

#include "./lib/include/my_lib.h"
#include "../include/my_navy.h"
#include "../include/struct.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int is_a_boat_part_2(my_boats_t *b, int x, int y)
{
    if ((x == b->boat4.x1) && (x == b->boat4.x2))
        if ((y >= b->boat4.y1) && (y <= b->boat4.y2) && (b->map[x][y] == 0))
            b->map[x][y] += 4;
    if ((y == b->boat4.y1) && (y == b->boat4.y2))
        if ((x >= b->boat4.x1) && (x <= b->boat4.x2) && (b->map[x][y] == 0))
            b->map[x][y] += 4;
    if ((x == b->boat5.x1) && (x == b->boat5.x2))
        if ((y >= b->boat5.y1) && (y <= b->boat5.y2) && (b->map[x][y] == 0))
            b->map[x][y] += 5;
    if ((y == b->boat5.y1) && (y == b->boat5.y2))
        if ((x >= b->boat5.x1) && (x <= b->boat5.x2) && (b->map[x][y] == 0))
            b->map[x][y] += 5;
    if (b->map[x][y] > 5)
        return 84;
    return 0;
}

int is_a_boat(my_boats_t *b, int x, int y)
{
    if (((x == b->boat2.x1) && (y == b->boat2.y1)) ||
    ((x == b->boat2.x2) && (y == b->boat2.y2)) ||
    ((x == b->boat2.x1) && (y == b->boat2.y2)) ||
    ((x == b->boat2.x1) && (y == b->boat2.y1)))
            b->map[x][y] += 2;
    if ((x == b->boat3.x1) && (x == b->boat3.x2))
        if ((y >= b->boat3.y1) && (y <= b->boat3.y2) && (b->map[x][y] == 0))
            b->map[x][y] += 3;
    if ((y == b->boat3.y1) && (y == b->boat3.y2))
        if ((x >= b->boat3.x1) && (x <= b->boat3.x2) && (b->map[x][y] == 0))
            b->map[x][y] += 3;
    return is_a_boat_part_2(b, x, y);
}

int check_boats(my_boats_t *my_boat)
{
    int error = 0;

    for (int i = 0; i != 9; i ++) {
        for (int y = 0; y != 9; y ++) {
            error = is_a_boat(my_boat, i, y);
        }
        if (error == 84) {
            write(2, "my_navy: error wrong boat placement!", 37);
            return 84;
        }
    }
    return 0;
}

void malloc_struct(my_boats_t *my_boats)
{
    my_boats->map = malloc(sizeof(char *) * 12);
    my_boats->mapmine = malloc(sizeof(char *) * 12);
    for (int i = 0; i != 9; i ++) {
        my_boats->map[i] = malloc(sizeof(char) * 12);
        my_boats->mapmine[i] = malloc(sizeof(char) * 12);
    }
}
