/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** AComponent
*/

#include "Component/AComponent.hpp"
#include <stdexcept>
#include <iostream>

void nts::AComponent::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin)
{
    if (pin > _pinMax) {
        throw std::invalid_argument("The pin wished is out of range");
    }
    _links[pin].setComponent(other);
    _links[pin].setPin(pin - 1);
    _links[pin].setOtherPin(otherPin);
}

nts::Tristate nts::AComponent::getLink(std::size_t pin)
{
    if (pin > _pinMax) {
        throw std::invalid_argument("The pin wished is out of range");
    }
    return (_links[pin].getComponent()->compute(_links[pin].getOtherPin()));
}

// Getters

std::size_t nts::AComponent::getPinMax() const
{
    return _pinMax;
}


nts::Tristate nts::AComponent::getState() const
{
    return _state;
}
