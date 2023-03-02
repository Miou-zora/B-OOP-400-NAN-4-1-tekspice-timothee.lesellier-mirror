/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4069
*/

#include "Component/Chip/Component4069.hpp"
#include <iostream>

nts::Component4069::Component4069()
{
    _pinMax= 13;
    _notComponents = {
                        std::make_shared<nts::NotComponent>(),
                        std::make_shared<nts::NotComponent>(),
                        std::make_shared<nts::NotComponent>(),
                        std::make_shared<nts::NotComponent>(),
                        std::make_shared<nts::NotComponent>(),
                        std::make_shared<nts::NotComponent>()
                    };

    _outputs = {
                {2, *(_notComponents.at(0).get())},
                {4, *(_notComponents.at(1).get())},
                {6, *(_notComponents.at(2).get())},
                {8, *(_notComponents.at(3).get())},
                {10, *(_notComponents.at(4).get())},
                {12, *(_notComponents.at(5).get())}
                };

    _inputs = {
                {1, std::pair<std::size_t, nts::IComponent&>(1, *(_notComponents.at(0).get()))},
                {3, std::pair<std::size_t, nts::IComponent&>(1, *(_notComponents.at(1).get()))},
                {5, std::pair<std::size_t, nts::IComponent&>(1, *(_notComponents.at(2).get()))},
                {9, std::pair<std::size_t, nts::IComponent&>(1, *(_notComponents.at(3).get()))},
                {11, std::pair<std::size_t, nts::IComponent&>(1, *(_notComponents.at(4).get()))},
                {13, std::pair<std::size_t, nts::IComponent&>(1, *(_notComponents.at(5).get()))},
                };
}

nts::Component4069::~Component4069()
{
}

nts::Tristate nts::Component4069::compute(std::size_t pin)
{
    try {
        return _outputs.at(pin).compute(2);
    } catch (std::out_of_range &e) {
        throw std::invalid_argument("Pin out of range");
    }
}

void nts::Component4069::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin)
{
    try {
        for (auto &ouput: _outputs) {
            if (ouput.first == pin)
                return;
        }
        _inputs.at(pin).second.setLink(_inputs.at(pin).first, other, otherPin);
    } catch (std::out_of_range &e) {
        throw std::invalid_argument("Pin out of range");
    }
}