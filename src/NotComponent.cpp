/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bootstrap-tekspice
** File description:
** NotComponent
*/

#include "NotComponent.hpp"

nts::NotComponent::NotComponent()
{
    _pinMax = 2;
    _state = nts::Tristate::Undefined;
}

nts::NotComponent::~NotComponent()
{
}

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    if (pin != _pinMax) {
        throw std::invalid_argument("Pin out of range");
    } else if (_links.count(1) == 0 || _links[1].component == nullptr) {
        return nts::Tristate::Undefined;
    } else {
        return ntsNot(_links[1].component->compute(_links[1].otherPin));
    }
}