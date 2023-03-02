/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4071
*/

#include "Component/Chip/Component4071.hpp"
#include <iostream>

nts::Component4071::Component4071()
{
    _pinMax= 13;
    _orComponents = {
                        std::make_shared<nts::OrComponent>(),
                        std::make_shared<nts::OrComponent>(),
                        std::make_shared<nts::OrComponent>(),
                        std::make_shared<nts::OrComponent>()
                    };

    _outputs = {
                {3, *(_orComponents.at(0).get())},
                {4, *(_orComponents.at(1).get())},
                {10, *(_orComponents.at(2).get())},
                {11, *(_orComponents.at(3).get())}
                };

    _inputs = {
                {1, std::pair<std::size_t, nts::IComponent&>(1, *(_orComponents.at(0).get()))},
                {2, std::pair<std::size_t, nts::IComponent&>(2, *(_orComponents.at(0).get()))},
                {5, std::pair<std::size_t, nts::IComponent&>(1, *(_orComponents.at(1).get()))},
                {6, std::pair<std::size_t, nts::IComponent&>(2, *(_orComponents.at(1).get()))},
                {8, std::pair<std::size_t, nts::IComponent&>(1, *(_orComponents.at(2).get()))},
                {9, std::pair<std::size_t, nts::IComponent&>(2, *(_orComponents.at(2).get()))},
                {12, std::pair<std::size_t, nts::IComponent&>(1, *(_orComponents.at(3).get()))},
                {13, std::pair<std::size_t, nts::IComponent&>(2, *(_orComponents.at(3).get()))},
                };
}

nts::Component4071::~Component4071()
{
}

nts::Tristate nts::Component4071::compute(std::size_t pin)
{
    try {
        return _outputs.at(pin).compute(3);
    } catch (std::out_of_range &e) {
        throw std::invalid_argument("Pin out of range");
    }
}

void nts::Component4071::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin)
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