/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Shell
*/

#include "Shell.hpp"
#include <string.h>
#include "Component/IO/AIO.hpp"

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
        this->executeCommand(this->_command);
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

    if (commandName == "exit") {
        this->_exit = true;
        return true;
    } else if (commandName == "simulate") {
        _circuit->simulate(1);
        return true;
    } else if (commandName == "loop") {
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
    std::string temp;

    current = strtok(cstr, sep.c_str());
    while (current != NULL) {
        temp = current;
        arr.push_back(temp);
        current = strtok(NULL, sep.c_str());
    }
    return arr;
}

bool Shell::excecuteValueAttriution(std::string command)
{
    std::vector<std::string> commandSplit = this->split(command, "=");
    std::vector<std::string> states = {"0", "1", "U"};
    std::vector<nts::Tristate> ntsStates = {nts::False, nts::True, nts::Undefined};
    nts::AIO *temp;

    if (commandSplit.size() != 2)
        return false;
    temp = dynamic_cast<nts::AIO*>(&_circuit->getComponent(commandSplit.at(0)));
    if (temp == nullptr)
        return false;
    for (int i = 0; i < 3; i++) {
        if (commandSplit.at(1) == states[i]) {
            temp->setNextState(ntsStates[i]);
            return true;
        }
    }
    return false;
}