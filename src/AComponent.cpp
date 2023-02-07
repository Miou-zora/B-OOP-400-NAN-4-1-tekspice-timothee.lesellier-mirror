/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bootstrap-tekspice
** File description:
** AComponent
*/

#include "AComponent.hpp"

void nts::AComponent::setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin)
{
    if (pin > _pinMax) {
        throw std::invalid_argument("The pin wished is out of range");
    }
    _links[pin] = *(new nts::Link);
    _links[pin].component = &other;
    _links[pin].pin = pin - 1;
    _links[pin].otherPin = otherPin;
}

nts::Tristate nts::AComponent::getLink(std::size_t pin)
{
    if (pin > _pinMax) {
        throw std::invalid_argument("The pin wished is out of range");
    }
    return (_links[pin].component->compute(_links[pin].otherPin));
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

std::ostream& operator<<(std::ostream& stream, nts::Tristate v)
{
    if (v == nts::Tristate::False) {
        stream << "0";
    } else if (v == nts::Tristate::True) {
        stream << "1";
    } else {
        stream << "U";
    }
    return stream;
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