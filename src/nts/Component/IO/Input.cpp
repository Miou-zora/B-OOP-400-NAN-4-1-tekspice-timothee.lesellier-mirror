/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Input
*/

#include "Component/IO/Input.hpp"
#include <stdexcept>

nts::Input::Input()
{
    _pinMax = 1;
    _state = nts::Tristate::Undefined;
    _nextState = nts::Tristate::Undefined;
}

nts::Input::~Input()
{

}

nts::Tristate nts::Input::compute(std::size_t pin)
{
    if (pin != 1) {
        throw std::invalid_argument("Pin out of range");
    } else {
        return _state;
    }
}

void nts::Input::simulate(std::size_t tick)
{
    (void)tick;
    _state = _nextState;
}
