/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Clock
*/

#include "Component/IO/Clock.hpp"

nts::Clock::Clock()
{
    _pinMax = 1;
    for (std::size_t i = 0; i < _pinMax; i++)
        _links[i] = nullptr;
    _state = nts::Tristate::Undefined;
    _nextState = nts::Tristate::Undefined;
}

nts::Clock::~Clock()
{
}

nts::Tristate nts::Clock::compute(std::size_t pin)
{
    if (pin != 1) {
        throw std::invalid_argument("Pin out of range");
    } else {
        return _state;
    }
}

void nts::Clock::simulate(std::size_t tick)
{
    (void)tick;
    if (_updated == true)
        return;
    _state = _nextState;
    if (_nextState == nts::Tristate::True)
        _nextState = nts::Tristate::False;
    else if (_state == nts::Tristate::False)
        _nextState = nts::Tristate::True;
    else
        _nextState = nts::Tristate::Undefined;
    _updated = true;
}
