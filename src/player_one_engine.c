/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** player one game handling
*/

#include "lib/include/my_lib.h"
#include "../include/my_navy.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int check_attack_conformity(char *line)
{
    if (my_strlen(line) != 3)
        return 84;
    if ((line[0] < 'A') || (line[0] > 'H'))
        return 84;
    if ((line[1] < '1') || (line[1] > '8'))
        return 84;
    return 1;
}

void send_value(char *line, int player_two_pid)
{
    send_int(line[0] - 'A' + 1, player_two_pid);
    get_value();
    send_int(line[1] - '1' + 1, player_two_pid);
}

void print_hit_status(my_boats_t *my_boat, int back, char *line)
{
    int status = 0;

    status = get_value();
    if (status == 1) {
        my_putstr(":missed\n");
        my_boat->mapmine[line[1] - '1'][line[0] - 'A'] = 1;
    }
    if (status == 2) {
        my_putstr(":hit\n");
        my_boat->mapmine[line[1] - '1'][line[0] - 'A'] = 2;
    }
    if (back == 0) {
        my_putchar('\n');
    }
}

void print_missing_output(char *line, int player_two_pid, my_boats_t *my_boats,
    int ennemy_hit)
{
    my_putstr("\nresult: ");
    my_putchar(line[0]);
    my_putnbr(line[1] - '0');
    send_value(line, player_two_pid);
    print_hit_status(my_boats, 1, line);
    ennemy_hit = get_hit(player_two_pid);
    print_hit_info(ennemy_hit, my_boats, player_two_pid);
}

int game_player_one(int player_two_pid, my_boats_t *my_boats)
{
    int game_status = 0;
    int ennemy_hit;
    int to_get_value;
    char *line = NULL;
    size_t len = 0;

    while (game_status == 0) {
        drawmap(my_boats);
        my_putstr("\n\nattack: ");
        if (getline(&line, &len, stdin) == -1)
            return 42;
        while (check_attack_conformity(line) == 84) {
            my_putstr("\nwrong position\n\nattack: ");
            getline(&line, &len, stdin);
        }
        print_missing_output(line, player_two_pid, my_boats, ennemy_hit);
        game_status = check_end_game(my_boats);
    }
}
