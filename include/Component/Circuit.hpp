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
    #include <memory>
    #include "Component/IComponent.hpp"

namespace nts {
    class Circuit : virtual public nts::IComponent{
        public:
            Circuit(void);
            ~Circuit(void);

            nts::IComponent &getInput(std::string name);
            nts::IComponent &getOutput(std::string name);
            nts::IComponent &getComponent(std::string name);

            bool addInput(std::shared_ptr<nts::IComponent> input, std::string name);
            bool addOutput(std::shared_ptr<nts::IComponent> output, std::string name);
            bool addComponent(std::shared_ptr<nts::IComponent> component, std::string name);

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin);
            void setLink(std::string firstName, std::size_t firstPin, std::string secondName, std::size_t secondPin);
            void display();

        protected:
        private:
            std::map<std::string, std::shared_ptr<nts::IComponent>> _components;
            std::map<std::string, std::shared_ptr<nts::IComponent>> _output;
            std::map<std::string, std::shared_ptr<nts::IComponent>> _input;

    };
}

#endif /* !CIRCUIT_HPP_ */