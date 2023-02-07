/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bootstrap-tekspice
** File description:
** FalseComponent
*/

#include "FalseComponent.hpp"

nts::FalseComponent::FalseComponent()
{
    _pinMax = 1;
    _state = nts::Tristate::False;
}

nts::FalseComponent::~FalseComponent()
{
}

nts::Tristate nts::FalseComponent::compute(std::size_t pin)
{
    pin--;
    if (pin > _pinMax) {
        throw std::invalid_argument("Pin out of range\n");
    }
    return _state;
}
