/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Shell
*/

#include "Shell.hpp"
#include <string.h>

Shell::Shell()
{
    _exit = false;
    _command = "";
    //circuit = nullptr;
}

Shell::~Shell()
{
}

void Shell::run()
{
    while (!this->_exit) {
        this->_command = this->getCommand();
        if (!this->executeCommand(this->_command)) {
            std::cout << "Invalid command" << std::endl;
        }
    }
}

std::string Shell::getCommand()
{
    std::string command;

    std::cout << "$> ";
    std::getline(std::cin, command);
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
    }
    for (std::size_t i = 0; i < commands.size(); i++) {
        if (commandName == commands[i]) {
            std::cout << "Command " << commandName << " executed" << std::endl;
            return true;
        }
    }
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
    std::cout << "Command " << commandSplit[0] << " = " << commandSplit[1] << " executed" << std::endl;
    // make a safe get to the circuit and set the value (if it exists)
    return true;
}