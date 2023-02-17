/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** UndefinedComponent
*/

#include "Component/Boolean/UndefinedComponent.hpp"
#include <stdexcept>

nts::UndefinedComponent::UndefinedComponent()
{
}

nts::UndefinedComponent::~UndefinedComponent()
{
}

nts::Tristate nts::UndefinedComponent::compute(std::size_t pin)
{
    if (pin == 1)
        return (nts::Undefined);
    else
        throw std::invalid_argument("Pin out of range");
}