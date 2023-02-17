/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Circuit
*/

#include "Component/Circuit.hpp"
#include "Component/IO/Output.hpp"

nts::Circuit::Circuit(void)
{
}

nts::Circuit::~Circuit(void)
{
}

nts::IComponent &nts::Circuit::getInput(std::string name)
{
    if (_input.find(name) == _input.end())
        throw std::runtime_error("Input not found");
    if (_input[name] == nullptr)
        throw std::runtime_error("Input nullptr");
    return *_input[name];
}

nts::IComponent &nts::Circuit::getOutput(std::string name)
{
    if (_output.find(name) == _output.end())
        throw std::runtime_error("Output not found");
    if (_output[name] == nullptr)
        throw std::runtime_error("Output nullptr");
    return *_output[name];
}

nts::IComponent &nts::Circuit::getComponent(std::string name)
{
    if (_components.find(name) != _components.end()) {
        if (_components[name] == nullptr)
            throw std::runtime_error("Component nullptr");
        return *_components[name];
    }
    if (_input.find(name) != _input.end()) {
        if (_input[name] == nullptr)
            throw std::runtime_error("Component nullptr");
        return *_input[name];
    }
    if (_output.find(name) != _output.end()) {
        if (_output[name] == nullptr)
            throw std::runtime_error("Component nullptr");
        return *_output[name];
    }
    throw std::runtime_error("Component not found");
}


bool nts::Circuit::addInput(std::shared_ptr<nts::IComponent> input, std::string name)
{
    if (_components.find(name) != _components.end())
        return false;
    _input[name] = input;
    _components[name] = input;
    return true;
}

bool nts::Circuit::addOutput(std::shared_ptr<nts::IComponent> output, std::string name)
{
    if (_components.find(name) != _components.end())
        return false;
    _output[name] = output;
    _components[name] = output;
    return true;
}

bool nts::Circuit::addComponent(std::shared_ptr<nts::IComponent> component, std::string name)
{
    if (_components.find(name) != _components.end())
        return false;
    _components[name] = component;
    return true;
}

void nts::Circuit::simulate(std::size_t tick)
{
    _tick += tick;
    for (auto &input : _input) {
        input.second->simulate(tick);
    }
}

nts::Tristate nts::Circuit::compute(std::size_t pin)
{
    (void)pin;
    for (auto &it : _output) {
        if (it.second != nullptr) {
            if (it.second->compute(1) == -1)
                std::cout << "  " << it.first << ": U" << std::endl;
            else
                std::cout << "  " << it.first << ": " << it.second->compute(1) << std::endl;
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
    std::cout << "inputs(s): " << std::endl;

    for (auto &input : _input) {
        std::cout << "\t" << input.first << ": " << input.second->compute(1) << std::endl;
    }

    std::cout << "output(s): " << std::endl;
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