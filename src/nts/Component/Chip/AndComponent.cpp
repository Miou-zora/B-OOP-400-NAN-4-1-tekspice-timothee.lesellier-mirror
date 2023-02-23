/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** AndComponent
*/

#include "Component/Chip/AndComponent.hpp"
#include <stdexcept>
#include <iostream>

nts::AndComponent::AndComponent()
{
    _pinMax = 3;
    for (std::size_t i = 0; i < _pinMax; i++)
        _links[i] = nullptr;
}

nts::AndComponent::~AndComponent()
{
}

nts::Tristate ntsAnd(nts::Tristate v, nts::Tristate v2)
{
    if (v == nts::Tristate::Undefined || v2 == nts::Tristate::Undefined) {
        return (nts::Tristate::Undefined);
    }
    if (v == v2 && v == nts::Tristate::True) {
        return (nts::Tristate::True);
    }
    return (nts::Tristate::False);
}

nts::Tristate nts::AndComponent::compute(std::size_t pin)
{
    if (pin != _pinMax) {
        throw std::invalid_argument("Pin out of range");
    } else {
        if (_links[1] == nullptr || _links[2] == nullptr) {
            return nts::Tristate::Undefined;
        }
        return ntsAnd(_links[1]->getComponent().compute(_links[1]->getOtherPin()), _links[2]->getComponent().compute(_links[2]->getOtherPin()));
    }
}

