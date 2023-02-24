/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4081
*/

#include "Component/Chip/Component4081.hpp"
#include "Component/Chip/AndComponent.hpp"
#include <iostream>

nts::Component4081::Component4081()
{
    _pinMax= 13;
    _andComponents = {std::make_shared<nts::AndComponent>(), std::make_shared<nts::AndComponent>(),
                    std::make_shared<nts::AndComponent>(), std::make_shared<nts::AndComponent>()};
    _outputs = {{3, *(_andComponents.at(0).get())}, {4, *(_andComponents.at(1).get())}, {10,
                *(_andComponents.at(2).get())}, {11, *(_andComponents.at(3).get())}};

    /*
        We virtualize the connexion, each input of the cheap is linked to a AndGate and the pin of connexion
    */
    _inputs =  {{1, std::pair<std::size_t, nts::IComponent&>(1, *(_andComponents.at(0).get()))},
                {2, std::pair<std::size_t, nts::IComponent&>(2, *(_andComponents.at(0).get()))},
                {5, std::pair<std::size_t, nts::IComponent&>(1, *(_andComponents.at(1).get()))},
                {6, std::pair<std::size_t, nts::IComponent&>(2, *(_andComponents.at(1).get()))},
                {8, std::pair<std::size_t, nts::IComponent&>(1, *(_andComponents.at(2).get()))},
                {9, std::pair<std::size_t, nts::IComponent&>(2, *(_andComponents.at(2).get()))},
                {12, std::pair<std::size_t, nts::IComponent&>(1, *(_andComponents.at(3).get()))},
                {13, std::pair<std::size_t, nts::IComponent&>(2, *(_andComponents.at(3).get()))},
                };
}

nts::Component4081::~Component4081()
{
}

nts::Tristate nts::Component4081::compute(std::size_t pin)
{
    for (auto &output : _outputs) {
        if (output.first == pin) {
            return output.second.compute(3);
        }
    }
    throw std::invalid_argument("Pin out of range");
}

void nts::Component4081::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin)
{
    if (pin == 7 || pin == 14) {
        throw std::invalid_argument("Pin out of range");
    }
    for (auto &input : _inputs) {
        if (input.first == pin) {
            input.second.second.setLink(input.second.first, other, otherPin);
            return;
        }
    }
}