/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** NandComponent
*/

#include "Component/Chip/NandComponent.hpp"
#include <stdexcept>
#include <iostream>

nts::NandComponent::NandComponent()
{
    _pinMax = 3;
    for (std::size_t i = 0; i < _pinMax; i++)
        _links[i] = nullptr;
}

nts::NandComponent::~NandComponent()
{
}

nts::Tristate ntsNand(nts::Tristate v, nts::Tristate v2)
{
    if (v == nts::Tristate::True && v2 == nts::Tristate::True) {
        return nts::Tristate::False;
    } else if (v == nts::Tristate::False || v2 == nts::Tristate::False) {
        return nts::Tristate::True;
    } else {
        return nts::Tristate::Undefined;
    }
}

nts::Tristate nts::NandComponent::compute(std::size_t pin)
{
    if (pin != _pinMax) {
        throw std::invalid_argument("Pin out of range");
    } else {
        if (_links[1] == nullptr || _links[2] == nullptr) {
            return nts::Tristate::Undefined;
        }
        return ntsNand(_links[1]->getComponent().compute(_links[1]->getOtherPin()), _links[2]->getComponent().compute(_links[2]->getOtherPin()));
    }
}

