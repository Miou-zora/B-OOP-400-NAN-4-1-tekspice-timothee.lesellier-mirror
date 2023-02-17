/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Output
*/

#include "Component/IO/Output.hpp"
#include <stdexcept>
#include <iostream>

nts::Output::Output()
{
    _pinMax = 1;
}

nts::Output::~Output()
{

}

nts::Tristate nts::Output::compute(std::size_t pin)
{
    if (pin != 1) {
        throw std::invalid_argument("Pin out of range");
    } else {
        return _links[1].getComponent()->compute(_links[1].getOtherPin());
    }
}

void nts::Output::display(void)
{
    std::cout << "Output: " << this->compute(1) << std::endl;
}