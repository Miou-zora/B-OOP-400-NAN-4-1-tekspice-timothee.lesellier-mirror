/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** XorComponent
*/

#include "Component/Chip/XorComponent.hpp"
#include <stdexcept>
#include <iostream>

nts::XorComponent::XorComponent()
{
    _pinMax = 3;
}

nts::XorComponent::~XorComponent()
{
}

nts::Tristate ntsXor(nts::Tristate v, nts::Tristate v2)
{
    if (v == nts::Tristate::Undefined || v2 == nts::Tristate::Undefined) {
        return (nts::Tristate::Undefined);
    }
    if (v == nts::Tristate::True && v2 == nts::Tristate::False) {
        return (nts::Tristate::True);
    }
    if (v == nts::Tristate::False && v2 == nts::Tristate::True) {
        return (nts::Tristate::True);
    }
    return (nts::Tristate::False);
}

nts::Tristate nts::XorComponent::compute(std::size_t pin)
{
    if (pin != _pinMax) {
        throw std::invalid_argument("Pin out of range");
    } else {
        if (_links[1] == nullptr || _links[2] == nullptr) {
            return nts::Tristate::Undefined;
        }
        return ntsXor(_links[1]->getComponent().compute(_links[1]->getOtherPin()), _links[2]->getComponent().compute(_links[2]->getOtherPin()));
    }
}

