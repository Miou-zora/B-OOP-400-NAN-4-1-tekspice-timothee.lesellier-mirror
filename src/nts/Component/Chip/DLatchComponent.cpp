/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** DLatchComponent
*/

#include "Component/Chip/DLatchComponent.hpp"
#include "Component/Chip/NotComponent.hpp"
#include <iostream>

nts::DLatchComponent::DLatchComponent()
{
    _pinMax= 4;
    for (std::size_t i = 0; i < _pinMax; i++)
        _links[i] = nullptr;
    _state = nts::Undefined;
}

nts::DLatchComponent::~DLatchComponent()
{
}

void nts::DLatchComponent::simulate(std::size_t ticks)
{
    if (_links[1] == nullptr || _links[2] == nullptr)
        throw std::invalid_argument("Pin not linked");
    if (_updated == true)
        return;
    _links[1]->getComponent().simulate(ticks);
    _links[2]->getComponent().simulate(ticks);
    if (_links[1]->getComponent().compute(_links[1]->getOtherPin()) == nts::True)
        _state = _links[2]->getComponent().compute(_links[2]->getOtherPin());
    else if (_links[1]->getComponent().compute(_links[1]->getOtherPin()) == nts::Undefined)
        _state = nts::Undefined;
    _updated = true;
}

nts::Tristate nts::DLatchComponent::compute(std::size_t pin)
{
    if ((pin != 3) && (pin != 4))
        throw std::invalid_argument("Pin out of range");
    else if (_links[1] == nullptr || _links[2] == nullptr)
        throw std::invalid_argument("Pin not linked");
    else if (_links[1]->getComponent().compute(_links[1]->getOtherPin()) == nts::Undefined)
        return nts::Undefined;
    else if (_links[1]->getComponent().compute(_links[1]->getOtherPin()) == nts::True)
    {
        if (_links[2]->getComponent().compute(_links[2]->getOtherPin()) == nts::Undefined)
            return nts::Undefined;
        if (pin == 3)
            return _links[2]->getComponent().compute(_links[2]->getOtherPin());
        else if (_links[2]->getComponent().compute(_links[2]->getOtherPin()) == nts::True)
            return nts::False;
        else
            return nts::True;
    }
    else
    {
        if (_state == nts::Undefined)
            return nts::Undefined;
        if (pin == 3)
            return _state;
        else if (_state == nts::True)
            return nts::False;
        else
            return nts::True;
    }
}