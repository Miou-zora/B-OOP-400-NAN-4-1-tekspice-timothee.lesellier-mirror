/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** SAdder
*/

#include "Component/Chip/SAdder.hpp"
#include "Component/Chip/AndComponent.hpp"
#include "Component/Chip/OrComponent.hpp"
#include "Component/Chip/XorComponent.hpp"

nts::SAdder::SAdder()
{
    _pinMax = 5;
    _components = {
                std::make_shared<nts::XorComponent>(), // XOR1 P1:1 && P2:2
                std::make_shared<nts::AndComponent>(), // AND P1:1 && P2:2
                std::make_shared<nts::XorComponent>(), // XOR P1:XOR1->3 && P2:3
                std::make_shared<nts::AndComponent>(), // AND P1:XOR1->3 && P2:3
                std::make_shared<nts::OrComponent>(), // OR P1:AND->3 && P2:AND1->3
    };
    _outputs = {
            {5, *_components[4]}, // OR->3
            {4, *_components[2]}, // XOR->3
    };
    _inputs = {
            {1, {{1, *_components[0]}, {1, *_components[1]}}},
            {2, {{2, *_components[0]}, {2, *_components[1]}}},
            {3, {{2, *_components[2]}, {2, *_components[3]}}},
    };

    _components[2]->setLink(1, _components[0], 3);
    _components[3]->setLink(1, _components[0], 3);
    _components[4]->setLink(1, _components[3], 3);
    _components[4]->setLink(2, _components[1], 3);
};


nts::SAdder::~SAdder()
{
}

void nts::SAdder::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin)
{
    try {
        for (auto &input : _inputs.at(pin)) {
            input.second.setLink(input.first, other, otherPin);
        }
    } catch (std::out_of_range &e) {
        throw std::invalid_argument("Pin out of range");
    }
}

nts::Tristate nts::SAdder::compute(std::size_t pin)
{
    try {
        return _outputs.at(pin).compute(3);
    } catch (std::out_of_range &e) {
        throw std::invalid_argument("Pin out of range");
    }
}
