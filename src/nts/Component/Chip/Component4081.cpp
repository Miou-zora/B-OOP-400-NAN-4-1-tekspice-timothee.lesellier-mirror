/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4081
*/

#include "Component/Chip/Component4081.hpp"
#include "Component/Chip/AndComponent.hpp"
#include <iostream>

nts::Component4081::Component4081()
{
    _pinMax= 13;
    _andComponent = std::make_shared<nts::AndComponent>();
    _inputPin1 = std::make_shared<nts::Input>();
    _inputPin2 = std::make_shared<nts::Input>();
    _andComponent->setLink(1, _inputPin1, 1);
    _andComponent->setLink(2, _inputPin2, 1);
    _outputs = {3, 4, 10, 11};
    _inputs = {{3, {1, 2}}, {4, {5, 6}}, {11, {12, 13}}, {10, {8, 9}}};
}

nts::Component4081::~Component4081()
{
}

nts::Tristate nts::Component4081::safeCompute(std::size_t pin)
{
    std::size_t pin1 = _inputs.at(pin).at(0);
    std::size_t pin2 = _inputs.at(pin).at(1);
    std::shared_ptr<IComponent> cmpnt1;
    std::shared_ptr<IComponent> cmpnt2;
    std::size_t pinCompute = 0;

    if (!_links.contains(pin1) || !_links.contains(pin2) )
        return (nts::Tristate::Undefined);
    cmpnt1 = _links.at(pin1).getComponent();
    cmpnt2 = _links.at(pin2).getComponent();
    if (cmpnt1.get() == nullptr || cmpnt2.get() == nullptr)
        return (nts::Tristate::Undefined);
    pinCompute = _links.at(pin1).getOtherPin();
    if (pinCompute > 0)
        _inputPin1->setCurrentState(cmpnt1->compute(pinCompute));
    pinCompute = _links.at(pin2).getOtherPin();
    if (pinCompute > 0)
        _inputPin2->setCurrentState(cmpnt2->compute(pinCompute));
    return (_andComponent->compute(3));
}

nts::Tristate nts::Component4081::compute(size_t pin)
{
    for (auto &output_pin: _outputs) {
        if (output_pin == pin) {
            return (safeCompute(output_pin));
        }
    }
    throw std::invalid_argument("Pin out of range");
}
