/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Circuit
*/

#include "Component/Circuit.hpp"
#include "Component/IO/Output.hpp"
#include <iostream>

nts::Circuit::Circuit(void)
{
    _tick = 0;
}

nts::Circuit::~Circuit(void)
{
}

nts::IComponent &nts::Circuit::getInput(std::string name)
{
    if (_input.find(name) == _input.end())
        throw std::runtime_error("Input not found");
    return *_input[name];
}

nts::IComponent &nts::Circuit::getOutput(std::string name)
{
    if (_output.find(name) == _output.end())
        throw std::runtime_error("Output not found");
    return *_output[name];
}

nts::IComponent &nts::Circuit::getComponent(std::string name)
{
    if (_components.find(name) != _components.end()) {
        return *_components[name];
    }
    throw std::runtime_error("Component not found");
}


void nts::Circuit::addInput(std::shared_ptr<nts::IComponent> input, std::string name)
{
    if (_components.find(name) != _components.end())
        throw std::runtime_error("Input already exists");
    _input[name] = input;
    _components[name] = input;
}

void nts::Circuit::addOutput(std::shared_ptr<nts::IComponent> output, std::string name)
{
    if (_components.find(name) != _components.end())
        throw std::runtime_error("Output already exists");
    _output[name] = output;
    _components[name] = output;
}

void nts::Circuit::addComponent(std::shared_ptr<nts::IComponent> component, std::string name)
{
    if (_components.find(name) != _components.end())
        throw std::runtime_error("Component already exists");
    _components[name] = component;
}

void nts::Circuit::simulate(std::size_t tick)
{
    _tick += tick;
    for (auto &component : _components) {
        component.second->simulate(tick);
    }
}

nts::Tristate nts::Circuit::compute(std::size_t pin)
{
    (void)pin;
    for (auto &it : _output) {
        if (it.second != nullptr) {
            return it.second->compute(pin);
        }
    }
    return nts::Undefined;
}

void nts::Circuit::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin)
{
    (void)pin;
    (void)other;
    (void)otherPin;
}

void nts::Circuit::display()
{
    std::cout << "ticks: " << _tick << std::endl;
    std::cout << "input(s):" << std::endl;

    for (auto &input : _input) {
        std::cout << "\t" << input.first << ": " << input.second->compute(1) << std::endl;
    }

    std::cout << "output(s):" << std::endl;
    for (auto &output : _output) {
        std::cout << "\t" << output.first << ": " << output.second->compute(1) << std::endl;
    }
}

void nts::Circuit::setLink(std::string firstName, std::size_t firstPin, std::string secondName, std::size_t secondPin)
{
    if (_components.find(firstName) == _components.end() && _input.find(firstName) == _input.end() && _output.find(firstName) == _output.end())
        throw std::runtime_error("Component not found");
    if (_components.find(secondName) == _components.end() && _input.find(secondName) == _input.end() && _output.find(secondName) == _output.end())
        throw std::runtime_error("Component not found");
    _components[firstName]->setLink(firstPin, _components[secondName], secondPin);
    _components[secondName]->setLink(secondPin, _components[firstName], firstPin);
}