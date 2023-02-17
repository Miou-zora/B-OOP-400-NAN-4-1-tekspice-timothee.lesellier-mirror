/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Input
*/

#include "Component/IO/Input.hpp"
#include <stdexcept>
#include <iostream>

nts::Input::Input() : _currentState(nts::Tristate::Undefined), _nextState(nts::Tristate::Undefined)
{
    _pinMax = 1;
    _state = nts::Tristate::Undefined;
}

nts::Input::~Input()
{

}

nts::Tristate nts::Input::compute(std::size_t pin)
{
    (void)pin;
    return _state;
}

void nts::Input::simulate(std::size_t tick)
{
    (void)tick;
    _state = _nextState;
}


nts::Tristate nts::Input::getNextState(void)
{
    return _nextState;
}

nts::Tristate nts::Input::getCurrentState(void)
{
    return _state;
}


void nts::Input::setNextState(nts::Tristate nextState)
{
    _nextState = nextState;
}

void nts::Input::setCurrentState(nts::Tristate currentState)
{
    _state = currentState;
}

void nts::Input::display(void)
{
    std::cout << "Input: " << _state << std::endl;
}