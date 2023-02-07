/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bootstrap-tekspice
** File description:
** TrueComponent
*/

#include "TrueComponent.hpp"

nts::TrueComponent::TrueComponent()
: AComponent()
{
    _pinMax = 1;
    _state = nts::Tristate::True;
}

nts::TrueComponent::~TrueComponent()
{
}

nts::Tristate nts::TrueComponent::compute(std::size_t pin)
{
    if (pin > _pinMax) {
        throw std::invalid_argument("Pin out of range\n");
    }
    return _state;
}
