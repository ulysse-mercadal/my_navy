/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** struct file
*/

#ifndef DATA_STORAGE
    #define DATA_STORAGE

typedef struct coords_t {
    int x1;
    int x2;
    int y1;
    int y2;
} coords_t;

typedef struct my_boats_t {
    struct coords_t boat2;
    struct coords_t boat3;
    struct coords_t boat4;
    struct coords_t boat5;
    int **map;
    int **mapmine;
} my_boats_t;

#endif
