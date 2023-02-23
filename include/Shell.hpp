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
    #include <vector>

    #include "Component/Component.hpp"
    #include "Component/Circuit.hpp"

class Shell {
    public:
        Shell();
        ~Shell();

        void run();
        void setCircuit(std::unique_ptr<nts::Circuit> circuit);

    protected:
    private:

        bool _exit;
        std::string _command;
        std::unique_ptr<nts::Circuit> _circuit;
        bool _ctrlC;

        std::string getCommand();
        std::string getCommandName(std::string command);
        bool executeCommand(std::string command);
        bool isValueAttriution(std::string command);

        bool excecuteValueAttriution(std::string command);
        std::vector<std::string> split(std::string str, std::string sep);
};

#endif /* !SHELL_HPP_ */