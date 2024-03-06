/*
** EPITECH PROJECT, 2024
** lib_reworked
** File description:
** compare n char of a string
*/

#include "../include/my_lib.h"
int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (i != n) {
        if ((s1[i] != s2[i]) || (s2[i] == '\0'))
            return (s1[i] - s2[i]);
        i ++;
    }
    return (0);
}
