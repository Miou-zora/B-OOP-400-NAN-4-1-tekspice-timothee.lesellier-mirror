/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
    #define CIRCUIT_HPP_

    #include <iostream>
    #include <string>
    #include <map>
    #include <list>
    #include "Component/IComponent.hpp"

class Circuit : virtual public nts::IComponent{
    public:
        Circuit(std::list<nts::IComponent> input, std::list<nts::IComponent> output, std::list<nts::IComponent> components);
        ~Circuit();

        nts::IComponent *getInput(std::string name);
        nts::IComponent *getOutput(std::string name);
        nts::IComponent *getComponent(std::string name);

        bool addInput(nts::IComponent *input);
        bool addOutput(nts::IComponent *output);
        bool addComponent(nts::IComponent *component);

        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin);
        void display();

    protected:
    private:
        std::map<std::string, std::unique_ptr<nts::IComponent>> _components;
        std::map<std::string, std::unique_ptr<nts::IComponent>> _output;
        std::map<std::string, std::unique_ptr<nts::IComponent>> _input;

};

#endif /* !CIRCUIT_HPP_ */