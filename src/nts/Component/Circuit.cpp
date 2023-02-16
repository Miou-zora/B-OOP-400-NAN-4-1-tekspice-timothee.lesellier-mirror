/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Circuit
*/

#include "Component/Circuit.hpp"

nts::Circuit::Circuit(void)
{
}

nts::Circuit::~Circuit(void)
{
}

std::unique_ptr<nts::IComponent> nts::Circuit::getInput(std::string name)
{
    return std::move(_input[name]);
}

std::unique_ptr<nts::IComponent> nts::Circuit::getOutput(std::string name)
{
    return std::move(_output[name]);
}

std::unique_ptr<nts::IComponent> nts::Circuit::getComponent(std::string name)
{
    return std::move(_components[name]);
}


bool nts::Circuit::addInput(std::unique_ptr<nts::IComponent> input, std::string name)
{
    if (_input.find(name) != _input.end())
        return false;
    _input[name] = std::move(input);
    return true;
}

bool nts::Circuit::addOutput(std::unique_ptr<nts::IComponent> output, std::string name)
{
    if (_output.find(name) != _output.end())
        return false;
    _output[name] = std::move(output);
    return true;
}

bool nts::Circuit::addComponent(std::unique_ptr<nts::IComponent> component, std::string name)
{
    if (_components.find(name) != _components.end())
        return false;
    _components[name] = std::move(component);
    return true;
}

void nts::Circuit::simulate(std::size_t tick)
{
    (void)tick;
}

nts::Tristate nts::Circuit::compute(std::size_t pin)
{
    (void)pin;
}

void nts::Circuit::setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin)
{
    (void)pin;
    (void)other;
    (void)otherPin;
}
