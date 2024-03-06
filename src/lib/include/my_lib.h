/*
** EPITECH PROJECT, 2023
** bootstrap phoenix
** File description:
** phoenixlib.h
*/

#ifndef LIBRARY
    #define LIBRARY

void my_putchar(char c);
void my_putnbr(int nb);
int my_putfloat(float nbr, int presision);
void my_putstr(char const *str);
char *my_revstr(char *str);
int my_atoi(char const *str);
float my_atof(char const *str);
int my_pow(int nbr, int pow);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *str);
int my_strlen(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strstr(char *str, char const *to_find);
char **my_str_split(char *str, char *separators);
#endif
