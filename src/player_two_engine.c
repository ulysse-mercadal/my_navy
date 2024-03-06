/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** player two game handling
*/

#include "lib/include/my_lib.h"
#include "../include/my_navy.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int get_hit(int player_one_pid)
{
    int to_get_value;

    my_putstr("\nwaiting for enemy's attack...");
    to_get_value = get_value() * 10;
    send_int(1, player_one_pid);
    to_get_value += get_value();
    return to_get_value;
}

int check_if_is_a_hit(int y, int i, my_boats_t *my_boats)
{
    if ((my_boats->map[y - 1][i - 1] != 0) &&
    (my_boats->map[y - 1][i - 1] < 7)) {
        return 0;
    }
    return 1;
}

void print_hit_info(int ennemy_hit, my_boats_t *my_boats, int player_one_pid)
{
    int i = ennemy_hit / 10;
    int y = ennemy_hit % 10;

    my_putstr("\n\nresult: ");
    my_putchar(ennemy_hit / 10 + 64);
    my_putnbr(ennemy_hit % 10);
    if (check_if_is_a_hit(y, i, my_boats) != 0) {
        my_putstr(":missed\n\n");
        if (my_boats->map[y - 1][i - 1] != 9) {
            my_boats->map[y - 1][i - 1] = 8;
        }
        send_int(1, player_one_pid);
    } else {
        my_putstr(":hit\n\n");
        my_boats->map[y - 1][i - 1] = 9;
        send_int(2, player_one_pid);
    }
}

void print_last_output(char *line, my_boats_t *my_boats, int player_one_pid)
{
    my_putstr("\nresult: ");
    my_putchar(line[0]);
    my_putnbr(line[1] - '0');
    send_value(line, player_one_pid);
    print_hit_status(my_boats, 0, line);
}

int game_player_two(int player_one_pid, my_boats_t *my_boats)
{
    int game_status = 0;
    int ennemy_hit;
    char *line = NULL;
    size_t len = 0;

    while (game_status == 0) {
        drawmap(my_boats);
        my_putchar('\n');
        ennemy_hit = get_hit(player_one_pid);
        print_hit_info(ennemy_hit, my_boats, player_one_pid);
        my_putstr("attack: ");
        if (getline(&line, &len, stdin) == -1)
            return 42;
        while (check_attack_conformity(line) == 84) {
            my_putstr("\nwrong position\n\nattack: ");
            getline(&line, &len, stdin);
        }
        print_last_output(line, my_boats, player_one_pid);
        game_status = check_end_game(my_boats);
    }
}
