/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Shell
*/

#ifndef SHELL_HPP_
    #define SHELL_HPP_

    #include <iostream>
    #include <string>
    #include <fstream>
    #include <list>

    #include "Component/Component.hpp"

class Shell {
    public:
        Shell();
        ~Shell();

        void run();

    protected:
    private:

        std::string getCommand();
        std::string getCommandName(std::string command);
        bool executeCommand(std::string command);

        bool isCommandValid(std::string command);
        bool isCommand(std::string command);
        bool isInput(std::string command);
        bool isOutput(std::string command);
        bool isSimulate(std::string command);
        bool isLoop(std::string command);
        bool isExit(std::string command);
        bool isDisplay(std::string command);
};

#endif /* !SHELL_HPP_ */