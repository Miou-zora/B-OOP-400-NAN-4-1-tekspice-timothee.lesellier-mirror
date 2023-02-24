/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** NotComponent
*/

#include "Component/Chip/NotComponent.hpp"
#include <stdexcept>
#include <iostream>

nts::NotComponent::NotComponent()
{
    _pinMax = 2;
}

nts::NotComponent::~NotComponent()
{
}

nts::Tristate ntsNot(nts::Tristate v)
{
    if (v == nts::Tristate::Undefined) {
        return (nts::Tristate::Undefined);
    }
    if (v == nts::Tristate::True) {
        return (nts::Tristate::False);
    }
    return (nts::Tristate::True);
}

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    if (pin != _pinMax) {
        throw std::invalid_argument("Pin out of range");
    } else {
        if (_links[1] == nullptr) {
            return nts::Tristate::Undefined;
        }
        return ntsNot(_links[1]->getComponent().compute(_links[1]->getOtherPin()));
    }
}

