/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Output
*/

#include "Component/IO/Output.hpp"
#include <stdexcept>

nts::Output::Output()
{
    _pinMax = 1;
    for (std::size_t i = 0; i < _pinMax; i++)
        _links[i] = nullptr;
}

nts::Output::~Output()
{

}

nts::Tristate nts::Output::compute(std::size_t pin)
{
    if (pin != 1) {
        throw std::invalid_argument("Pin out of range");
    } else {
        if (_links[1] == nullptr) {
            return nts::Tristate::Undefined;
        } else {
            return _links[1]->getComponent().compute(_links[1]->getOtherPin());
        }
    }
}
