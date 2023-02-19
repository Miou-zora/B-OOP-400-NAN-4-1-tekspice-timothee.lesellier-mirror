/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bootstrap-tekspice
** File description:
** main
*/

#include "NTS.hpp"
#include <csignal>

bool ctrlC = false;

void sigintHandler(int sig_num)
{
    (void)sig_num;
    ctrlC = true;
}

int main(int ac, char **av)
{
    Shell shell;

    if (ac != 2) {
        return 84;
    }
    nts::Builder builder(av[1]);
    try {
        shell.setCircuit(builder.BuildCircuit());
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    signal(SIGINT, sigintHandler);
    shell.run();
    return 0;
}
