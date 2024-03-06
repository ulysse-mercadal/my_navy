/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** check file conformity
*/
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

#include "lib/include/my_lib.h"

#include "my_navy.h"
#include "../include/struct.h"

int check_boat_struct(char *line_content)
{
    int x1 = line_content[3] - '0';
    int x2 = line_content[6] - '0';
    int size = line_content[0] - '0';

    if ((line_content[2] != line_content[5]) &&
    (line_content[3] != line_content[6]))
        return 84;
    if (line_content[2] != line_content[5]) {
        if ((line_content[5] == (line_content[2] - size - 1)) ||
        (line_content[5] == (line_content[2] + size - 1))) {
            return 0;
        }
    } else {
        if ((x2 == (x1 - (size - 1))) || (x2 == (x1 + (size - 1)))) {
            return 0;
        }
    }
    return 84;
}

void fill_boat5(my_boats_t *my_boats, char *line_content)
{
    my_boats->boat5.y1 = line_content[2] - 'A';
    my_boats->boat5.y2 = line_content[5] - 'A';
    my_boats->boat5.x1 = line_content[3] - '0' - 1;
    my_boats->boat5.x2 = line_content[6] - '0' - 1;
    for (int i = 0; i != 9; i ++) {
        for (int y = 0; y != 9; y ++) {
            my_boats->map[i][y] = 0;
            my_boats->mapmine[i][y] = 0;
        }
    }
}

void fill_struct(int status, char *line_content, my_boats_t *my_boats)
{
    if (status == 2) {
        my_boats->boat2.y1 = line_content[2] - 'A';
        my_boats->boat2.y2 = line_content[5] - 'A';
        my_boats->boat2.x1 = line_content[3] - '0' - 1;
        my_boats->boat2.x2 = line_content[6] - '0' - 1;
    }
    if (status == 3) {
        my_boats->boat3.y1 = line_content[2] - 'A';
        my_boats->boat3.y2 = line_content[5] - 'A';
        my_boats->boat3.x1 = line_content[3] - '0' - 1;
        my_boats->boat3.x2 = line_content[6] - '0' - 1;
    }
    if (status == 4) {
        my_boats->boat4.y1 = line_content[2] - 'A';
        my_boats->boat4.y2 = line_content[5] - 'A';
        my_boats->boat4.x1 = line_content[3] - '0' - 1;
        my_boats->boat4.x2 = line_content[6] - '0' - 1;
    }
    if (status == 5)
        fill_boat5(my_boats, line_content);
}

int store_in_boat_struct(char *line_content, int status,
    struct my_boats_t *my_boats)
{
    if (((line_content[2] < 'A') || (line_content[2] > 'H')) ||
    ((line_content[5] < 'A') || (line_content[5] > 'H')) ||
    ((line_content[3] < '1') || (line_content[3] > '8')) ||
    ((line_content[6] < '1') || (line_content[6] > '8'))) {
        write(2, "my_navy: wrong file format\n", 28);
        return 84;
    }
    if (check_boat_struct(line_content) != 0) {
        write(2, "my_navy: wrong boat size or placment\n", 38);
        return 84;
    }
    fill_struct(status, line_content, my_boats);
    return 0;
}

int check_file(char const *file_name, struct my_boats_t *my_boats)
{
    char *buffer;
    char *line = NULL;
    int status = 2;
    size_t len = 0;
    size_t check = 0;
    FILE* fd = fopen(file_name, "r");

    malloc_struct(my_boats);
    if (fd == NULL) {
        write(2, "my_navy: no sutch file or directory\n", 36);
        return 84;
    }
    check = getline(&line, &len, fd);
    while (check != -1) {
        if (store_in_boat_struct(line, status, my_boats) != 0)
            return 84;
        check = getline(&line, &len, fd);
        status ++;
    }
    return 0;
}
