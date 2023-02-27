/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** AComponent
*/

#include "Component/AComponent.hpp"
#include <stdexcept>

void nts::AComponent::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin)
{
    if (pin > _pinMax) {
        throw std::invalid_argument("The pin wished is out of range");
    }
    if (this == other.get()) {
        throw std::invalid_argument("You can't link a component to itself");
    }
    _links[pin].reset(new nts::Link(*other.get(), otherPin));
}

std::size_t nts::AComponent::getPinMax() const
{
    return _pinMax;
}

void nts::AComponent::resetUpdate(void) {
    if (_updated == false)
        return;
    _updated = false;
    for (auto &link: _links) {
        if (link.second != nullptr) {
            link.second->getComponent().resetUpdate();
        }
    }
}

void nts::AComponent::simulate(std::size_t tick)
{
    if (_updated == true) {
        return;
    }
    _updated = true;
    for (auto &link: _links) {
        if (link.second.get() != nullptr) {
            link.second->getComponent().simulate(tick);
        }
    }
}