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
    _andComponents = {
                        std::make_shared<nts::AndComponent>(),
                        std::make_shared<nts::AndComponent>(),
                        std::make_shared<nts::AndComponent>(),
                        std::make_shared<nts::AndComponent>()
                    };

    _outputs = {
                {3, *(_andComponents.at(0).get())},
                {4, *(_andComponents.at(1).get())},
                {10, *(_andComponents.at(2).get())},
                {11, *(_andComponents.at(3).get())}
                };

    _inputs = {
                {1, std::pair<std::size_t, nts::IComponent&>(1, *(_andComponents.at(0).get()))},
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
    try {
        return _outputs.at(pin).compute(3);
    } catch (std::out_of_range &e) {
        throw std::invalid_argument("Pin out of range");
    }
}

void nts::Component4081::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin)
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