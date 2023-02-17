/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Shell
*/

#include "Shell.hpp"
#include <string.h>

extern bool ctrlC;

Shell::Shell()
{
    _exit = false;
    _command = "";
    _circuit = std::make_unique<nts::Circuit>();
}

Shell::~Shell()
{
}

void Shell::run()
{
    while (!this->_exit) {
        this->_command = this->getCommand();
        if (!this->executeCommand(this->_command) && !this->_exit) {
            std::cout << "Invalid command" << std::endl;
        }
    }
}

std::string Shell::getCommand()
{
    std::string command;

    std::cout << "> ";
    if (!std::getline(std::cin, command)) {
        this->_exit = true;
        return "";
    }
    return command;
}

std::string Shell::getCommandName(std::string command)
{
    std::string commandName = "";

    for (std::size_t i = 0; i < command.size(); i++) {
        if (command[i] == ' ')
            break;
        commandName += command[i];
    }
    return commandName;
}

bool Shell::executeCommand(std::string command)
{
    std::string commandName = this->getCommandName(command);
    std::vector<std::string> commands = {"simulate", "loop", "display"};

    if (commandName == "exit") {
        this->_exit = true;
        return true;
    } else if (commandName == "simulate") {
        _circuit->simulate(1);
        return true;
    } else if (commandName == "loop") {
        std::cout << "Press Ctrl+C to exit loop" << std::endl;
        while(!ctrlC) {
            _circuit->simulate(1);
        }
        ctrlC = false;
        return true;
    } else if (commandName == "display") {
        _circuit->display();
        return true;
    } else
    if (this->isValueAttriution(command)) {
        return this->excecuteValueAttriution(command);
    }
    return false;
}


bool Shell::isValueAttriution(std::string command)
{
    std::string commandName = this->getCommandName(command);

    if (commandName.find('=') != std::string::npos)
        return true;
    return false;
}

std::vector<std::string> Shell::split(std::string str, std::string sep)
{
    char *cstr = const_cast<char *>(str.c_str());
    char *current;
    std::vector<std::string> arr;

    current = strtok(cstr, sep.c_str());
    while (current != NULL) {
        arr.push_back(current);
        current = strtok(NULL, sep.c_str());
    }
    return arr;
}

bool Shell::excecuteValueAttriution(std::string command)
{
    std::vector<std::string> commandSplit = this->split(command, "=");

    if (commandSplit.size() < 2)
        return false;
    if (g)
    return true;
}