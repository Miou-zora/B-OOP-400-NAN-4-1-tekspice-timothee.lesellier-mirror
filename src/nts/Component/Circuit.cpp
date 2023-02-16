/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Circuit
*/

#include "Component/Circuit.hpp"

Circuit::Circuit(std::map<std::string, nts::IComponent> &components) : _components(components)
{

}

Circuit::~Circuit()
{

}

std::map<std::string, nts::IComponent> Circuit::getComponents() const
{
    return _components;
}


void Circuit::simulate(std::size_t tick)
{
    for (auto &component : _components) {
        component.second.simulate(tick);
    }
}

nts::Tristate Circuit::compute(std::size_t pin)
{

}

void Circuit::setLink(std::string name, std::size_t pin, std::string other, std::size_t otherPin)
{

}

void Circuit::setLink(std::pair<std::string, size_t> aComponent, std::pair<std::string, size_t> bComponent)
{

}
