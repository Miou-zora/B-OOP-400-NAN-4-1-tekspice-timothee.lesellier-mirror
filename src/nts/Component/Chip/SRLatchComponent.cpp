/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** SRLatchComponent
*/

#include "Component/Chip/SRLatchComponent.hpp"

nts::SRLatchComponent::SRLatchComponent()
{
    _pinMax = 4;
    for (std::size_t i = 0; i < _pinMax; i++)
        _links[i] = nullptr;
    _stateQ = nts::Undefined;
    _stateQBar = nts::Undefined;
}

nts::SRLatchComponent::~SRLatchComponent()
{

}

void nts::SRLatchComponent::simulate(std::size_t ticks)
{
    if (_links[1] == nullptr || _links[2] == nullptr)
        throw std::invalid_argument("Pin not linked");
    if (_updated == true)
        return;
    _links[1]->getComponent().simulate(ticks);
    _links[2]->getComponent().simulate(ticks);
    if (_links[1]->getComponent().compute(_links[1]->getOtherPin()) == nts::False) {
        if (_links[2]->getComponent().compute(_links[2]->getOtherPin()) == nts::False) {
            return;
        } else if (_links[2]->getComponent().compute(_links[2]->getOtherPin()) == nts::True) {
            _stateQ = nts::True;
            _stateQBar = nts::False;
        } else {
            _stateQ = nts::Undefined;
            _stateQBar = nts::Undefined;
        }
    }
    else if (_links[1]->getComponent().compute(_links[1]->getOtherPin()) == nts::True) {
        if (_links[2]->getComponent().compute(_links[2]->getOtherPin()) == nts::False) {
            _stateQ = nts::False;
            _stateQBar = nts::True;
        } else if (_links[2]->getComponent().compute(_links[2]->getOtherPin()) == nts::True) {
            _stateQ = nts::False;
            _stateQBar = nts::False;
        } else {
            _stateQ = nts::False;
            _stateQBar = nts::Undefined;
        }
    }
    else {
        if (_links[2]->getComponent().compute(_links[2]->getOtherPin()) == nts::False) {
            _stateQ = nts::Undefined;
            _stateQBar = nts::Undefined;
        } else if (_links[2]->getComponent().compute(_links[2]->getOtherPin()) == nts::True) {
            _stateQ = nts::Undefined;
            _stateQBar = nts::False;
        } else {
            _stateQ = nts::Undefined;
            _stateQBar = nts::Undefined;
        }
    }
    _updated = true;
}

nts::Tristate nts::SRLatchComponent::compute(std::size_t pin)
{
    if ((pin != 3) && (pin != 4))
        throw std::invalid_argument("Pin out of range");
    else if (_links[1] == nullptr || _links[2] == nullptr)
        throw std::invalid_argument("Pin not linked");
    if (_links[1]->getComponent().compute(_links[1]->getOtherPin()) == nts::False) {
        if (_links[2]->getComponent().compute(_links[2]->getOtherPin()) == nts::False) {
            if (pin == 3)
                return _stateQ;
            else
                return _stateQBar;
        } else if (_links[2]->getComponent().compute(_links[2]->getOtherPin()) == nts::True) {
            if (pin == 3)
                return nts::True;
            else
                return nts::False;
        } else {
            if (pin == 3)
                return nts::Undefined;
            else
                return nts::Undefined;
        }
    }
    else if (_links[1]->getComponent().compute(_links[1]->getOtherPin()) == nts::True) {
        if (_links[2]->getComponent().compute(_links[2]->getOtherPin()) == nts::False) {
            if (pin == 3)
                return nts::False;
            else
                return nts::True;
        } else if (_links[2]->getComponent().compute(_links[2]->getOtherPin()) == nts::True) {
            if (pin == 3)
                return nts::False;
            else
                return nts::False;
        } else {
            if (pin == 3)
                return nts::False;
            else
                return nts::Undefined;
        }
    }
    else {
        if (_links[2]->getComponent().compute(_links[2]->getOtherPin()) == nts::False) {
            if (pin == 3)
                return nts::Undefined;
            else
                return nts::Undefined;
        } else if (_links[2]->getComponent().compute(_links[2]->getOtherPin()) == nts::True) {
            if (pin == 3)
                return nts::Undefined;
            else
                return nts::False;
        } else {
            if (pin == 3)
                return nts::Undefined;
            else
                return nts::Undefined;
        }
    }
}