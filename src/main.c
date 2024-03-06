/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** main file
*/
#include "./lib/include/my_lib.h"
#include "../include/my_navy.h"
#include "../include/struct.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void check_nbr_hit(my_boats_t *my_boat, int i, int *ennemy, int *me)
{
    for (int y = 0; y != 9; y ++) {
        if (my_boat->map[i][y] > 8)
            (*ennemy) ++;
        if (my_boat->mapmine[i][y] == 2)
            (*me) ++;
    }
}

int check_end_game(my_boats_t *myboat)
{
    int nbr_hit_mine = 0;
    int nbr_hit_ennemy = 0;

    for (int i = 0; i != 9; i ++) {
        check_nbr_hit(myboat, i, &nbr_hit_ennemy, &nbr_hit_mine);
    }
    if (nbr_hit_ennemy == 14)
        return 1;
    if (nbr_hit_mine == 14)
        return 2;
    return 0;
}

int print_end_game(my_boats_t *myboat)
{
    int nbr_hit_mine = 0;
    int nbr_hit_ennemy = 0;

    for (int i = 0; i != 9; i ++) {
        check_nbr_hit(myboat, i, &nbr_hit_ennemy, &nbr_hit_mine);
    }
    if (nbr_hit_ennemy > 13) {
        drawmap(myboat);
        my_putstr("\n\n");
        my_putstr("Enemy won\n");
        return 1;
    }
    if (nbr_hit_mine > 13) {
        drawmap(myboat);
        my_putstr("\n\n");
        my_putstr("I won\n");
        return 0;
    }
    return 0;
}

int handle_player_two(int player_one_pid, my_boats_t *my_boats)
{
    struct sigaction sa;
    int player_two_pid = getpid();

    my_putstr("my_pid: ");
    my_putnbr(player_two_pid);
    if (kill(player_one_pid, SIGUSR1) != -1) {
        my_putstr("\n\nsuccessfully connected to enemy\n\n");
        game_player_two(player_one_pid, my_boats);
    } else
        my_putstr("\n\nconnection failed\n");
}

int main(int argc, char const *argv[])
{
    struct my_boats_t my_boats;

    if ((argc == 2) && (check_file(argv[1], &my_boats) == 0)) {
        if (check_boats(&my_boats) == 84) {
            return 84;
        }
        if (handle_player_one(&my_boats) == 42)
            return 0;
        return (print_end_game(&my_boats));
    }
    if ((argc == 3) && (check_file(argv[2], &my_boats) == 0) &&
    (my_atoi(argv[1]) > 0)) {
        if (check_boats(&my_boats) == 84) {
            return 84;
        }
        if (handle_player_two(my_atoi(argv[1]), &my_boats) == 42)
            return 0;
        return (print_end_game(&my_boats));
    }
    return 84;
}
