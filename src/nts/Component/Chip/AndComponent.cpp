/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** AndComponent
*/

#include "Component/Chip/AndComponent.hpp"
#include <stdexcept>

nts::AndComponent::AndComponent()
{
    _pinMax = 3;
    _state = nts::Tristate::Undefined;
}

nts::AndComponent::~AndComponent()
{
}

nts::Tristate ntsAnd(nts::Tristate v, nts::Tristate v2)
{
    if (v == nts::Tristate::Undefined || v2 == nts::Tristate::Undefined) {
        return (nts::Tristate::Undefined);
    }
    if (v == v2) {
        return (nts::Tristate::True);
    }
    return (nts::Tristate::False);
}

nts::Tristate nts::AndComponent::compute(std::size_t pin)
{
    if (pin != _pinMax) {
        throw std::invalid_argument("Pin out of range");
    } else if (_links[1].getComponent() == nullptr || _links[2].getComponent() == nullptr) {
        return nts::Tristate::Undefined;
    } else {
        return ntsAnd(_links[1].getComponent()->compute(_links[1].getOtherPin()), _links[2].getComponent()->compute(_links[2].getOtherPin()));
    }
}