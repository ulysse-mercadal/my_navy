/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** navy.h
*/

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "./struct.h"

#ifndef NAVY_H_
    #define NAVY_H_

int handle_player_one(my_boats_t *my_boats);
int game_player_one(int player_two_pid, my_boats_t *my_boats);
int game_player_two(int player_two_pid, my_boats_t *my_boats);
void handle_sig(int sig, siginfo_t *info);
int check_file(char const *file_name, my_boats_t *my_boats);
void send_int(int value_to_send, int reciver_pid);
int get_value(void);
int drawmap(my_boats_t *my_boats);
void handler(int signum);
void print_hit_info(int ennemy_hit, my_boats_t *my_boats, int player_one_pid);
void send_value(char *line, int player_two_pid);
void print_hit_status(my_boats_t *my_boat, int back, char *line);
int check_attack_conformity(char *line);
int get_hit(int player_one_pid);
int check_end_game(my_boats_t *myboat);
int check_boats(struct my_boats_t *my_boat);
void malloc_struct(my_boats_t *my_boats);
#endif
