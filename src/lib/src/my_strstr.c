/*
** EPITECH PROJECT, 2024
** lib_reworked
** File description:
** find a str in a str
*/

#include "../include/my_lib.h"

int check_rest(char *str, int i, char const *to_find)
{
    for (int y = 0; to_find[y] != '\0'; y ++) {
        if (str[i + y] != to_find[y])
            return 0;
    }
    return 1;
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;

    if (to_find[0] == '\0')
        return (&str[0]);
    while (str[i] != '\0') {
        if ((str[i] == to_find[0]) && (check_rest(str, i, to_find) == 1)) {
            return (&str[i]);
        }
        i++;
    }
    return 0;
}
