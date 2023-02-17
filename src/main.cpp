/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bootstrap-tekspice
** File description:
** main
*/

#include "NTS.hpp"
#include "Shell.hpp"
#include <csignal>

bool ctrlC = false;

void sigintHandler(int sig_num)
{
    ctrlC = true;
}

int main(void)
{
    signal(SIGINT, sigintHandler);
    Shell shell;
    shell.run();
    return 0;
}