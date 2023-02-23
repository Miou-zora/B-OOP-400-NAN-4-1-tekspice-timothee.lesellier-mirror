/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** OrComponent
*/

#include "Component/Chip/OrComponent.hpp"
#include <stdexcept>
#include <iostream>

nts::OrComponent::OrComponent()
{
    _pinMax = 3;
}

nts::OrComponent::~OrComponent()
{
}

nts::Tristate ntsOr(nts::Tristate v, nts::Tristate v2)
{
    if (v == nts::Tristate::True || v2 == nts::Tristate::True) {
        return (nts::Tristate::True);
    }
    if (v == nts::Tristate::Undefined || v2 == nts::Tristate::Undefined) {
        return (nts::Tristate::Undefined);
    }
    return (nts::Tristate::False);
}

nts::Tristate nts::OrComponent::compute(std::size_t pin)
{
    if (pin != _pinMax) {
        throw std::invalid_argument("Pin out of range");
    } else {
        if (_links[1].getComponent() == nullptr || _links[2].getComponent() == nullptr) {
            return nts::Tristate::Undefined;
        }
        return ntsOr(_links[1].getComponent()->compute(_links[1].getOtherPin()), _links[2].getComponent()->compute(_links[2].getOtherPin()));
    }
}
