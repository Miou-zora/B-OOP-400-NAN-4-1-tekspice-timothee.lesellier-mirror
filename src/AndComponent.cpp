/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bootstrap-tekspice
** File description:
** AndComponent
*/

#include "AndComponent.hpp"

nts::AndComponent::AndComponent()
{
    _pinMax = 3;
    _state = nts::Tristate::Undefined;
}

nts::AndComponent::~AndComponent()
{
}

nts::Tristate nts::AndComponent::compute(std::size_t pin)
{
    if (pin != _pinMax) {
        throw std::invalid_argument("Pin out of range");
    } else if (_links[1].component == nullptr || _links[2].component == nullptr) {
        return nts::Tristate::Undefined;
    } else {
        return ntsAnd(_links[1].component->compute(_links[1].otherPin), _links[2].component->compute(_links[2].otherPin));
    }
}