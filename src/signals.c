/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** signals handeling file
*/

#include "lib/include/my_lib.h"
#include "../include/my_navy.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int pid = 0;

void handle_sig(int sig, siginfo_t *info)
{
    int x = 0;

    pid = info->si_pid;
}

void handler(int signum)
{
    if (signum == SIGUSR1) {
        pid = (pid << 1) | 1;
    } else if (signum == SIGUSR2) {
        pid = (pid << 1);
    }
}

int handle_player_one(my_boats_t *my_boats)
{
    struct sigaction sa;
    int player_one_pid = getpid();
    int player_two_pid;

    my_putstr("my_pid: ");
    my_putnbr(player_one_pid);
    my_putstr("\n\nwaiting for enemy...");
    sa.sa_handler = &handle_sig;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    while ((pid == 0) || (pid == player_one_pid));
    my_putstr("\n\nenemy connected\n\n");
    player_two_pid = pid;
    game_player_one(player_two_pid, my_boats);
}

void send_int(int value_to_send, int reciver_pid)
{
    int value = 0;

    for (int i = 0; i < 32; i++) {
        if (value >= value_to_send) {
            pid = getpid();
            break;
        }
        if (value_to_send & (1 << i)){
            kill(reciver_pid, SIGUSR1);
            value = (value << 1) | 1;
        } else {
            kill(reciver_pid, SIGUSR2);
            value = (value << 1);
        }
        usleep(10000);
    }
}

int get_value(void)
{
    int value_to_get = -1;
    int status = 0;

    pid = 0;
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    while (1) {
        usleep(100000);
        status ++;
        if (status % 2 == 1)
            value_to_get = pid;
        if ((status % 2 == 0) && (pid != 0) && (pid == value_to_get))
            break;
    }
    return value_to_get;
}
