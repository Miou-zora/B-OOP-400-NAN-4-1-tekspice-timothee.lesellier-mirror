/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Circuit
*/

#pragma once

#include <string>
#include <map>
#include <memory>
#include "Component/IComponent.hpp"

namespace nts
{
    class Circuit : virtual public nts::IComponent {
        public:
            Circuit(void);
            ~Circuit(void);

            void addInput(std::shared_ptr<nts::IComponent> input, std::string name);
            nts::IComponent &getInput(std::string name);

            void addOutput(std::shared_ptr<nts::IComponent> output, std::string name);
            nts::IComponent &getOutput(std::string name);

            void addComponent(std::shared_ptr<nts::IComponent> component, std::string name);
            nts::IComponent &getComponent(std::string name);

            void setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin);
            void setLink(std::string firstName, std::size_t firstPin, std::string secondName, std::size_t secondPin);

            nts::Tristate compute(std::size_t pin);
            void simulate(std::size_t tick);
            void display();
            void resetUpdate(void);
        private:
            std::map<std::string, std::shared_ptr<nts::IComponent>> _components;
            std::map<std::string, std::shared_ptr<nts::IComponent>> _output;
            std::map<std::string, std::shared_ptr<nts::IComponent>> _input;

            size_t _tick;
    };
}