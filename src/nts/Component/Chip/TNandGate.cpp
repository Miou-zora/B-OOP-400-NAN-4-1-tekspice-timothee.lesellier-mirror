/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** TNandGate
*/

#include "Component/Chip/TNandgate.hpp"
#include <stdexcept>
#include <iostream>

nts::TNandGate::TNandGate()
{
    _pinMax = 4;

    _components = {
        std::make_shared<nts::AndComponent>(),
        std::make_shared<nts::AndComponent>(),
        std::make_shared<nts::NotComponent>(),
    };

    _outputs = {
        {4, *_components[2]}
    };

    _inputs = {
        {1, std::pair<std::size_t, nts::IComponent &>(1, *_components[0])},
        {2, std::pair<std::size_t, nts::IComponent &>(2, *_components[0])},
        {3, std::pair<std::size_t, nts::IComponent &>(2, *_components[1])},
    };

    _components[1]->setLink(1, _components[0], 3);
    _components[2]->setLink(1, _components[1], 3);
}

nts::TNandGate::~TNandGate()
{
}

void nts::TNandGate::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin)
{
    try {
        for (auto &output: _outputs) {
            if (output.first == pin)
                return;
        }
        _inputs.at(pin).second.setLink(_inputs.at(pin).first, other, otherPin);
    } catch (std::out_of_range &e) {
        throw std::invalid_argument("Pin out of range");
    }
}

nts::Tristate nts::TNandGate::compute(std::size_t pin)
{
    try {
        return _outputs.at(pin).compute(2);
    } catch (std::out_of_range &e) {
        throw std::invalid_argument("Pin out of range");
    }
}
