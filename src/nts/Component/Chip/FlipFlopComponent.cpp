/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** FlipFlopComponent
*/

#include "Component/Chip/FlipFlopComponent.hpp"
#include "Component/Chip/NotComponent.hpp"
#include "Component/Chip/InvSRNLatchComponent.hpp"
#include "Component/Chip/NandComponent.hpp"
#include "Component/Chip/NorComponent.hpp"

nts::FlipFlopComponent::FlipFlopComponent()
{
    _pinMax = 6;
    _components = {
                    std::make_shared<nts::NotComponent>(),        // 0 Data -> Not1:1
                    std::make_shared<nts::NandComponent>(),       // 1 Data + Clock -> Nand1
                    std::make_unique<nts::NandComponent>(),       // 2 Clock + Not1:2 -> Nand2
                    std::make_shared<nts::NotComponent>(),        // 3 Nand1:3 -> Not2:1
                    std::make_shared<nts::NotComponent>(),        // 4 Nand2:3 -> Not3:1
                    std::make_unique<nts::NorComponent>(),        // 5 Set + Not2:2 -> Nor1
                    std::make_unique<nts::NorComponent>(),        // 6 Reset + Not3:2 -> Nor2
                    std::make_unique<nts::InvSRNLatchComponent>() // 7 Nor1:2 + Nor2:2 -> Inv. SRN Latch
                };
    _outputs = {
                {5, *(_components.at(7).get())}, // Inv. SRN Latch:3
                {6, *(_components.at(7).get())}  // Inv. SRN Latch:4
                };

    _inputs = {
                {1, std::pair<std::size_t, nts::IComponent&>(1, *(_components.at(0).get()))}, // Data
                {2, std::pair<std::size_t, nts::IComponent&>(1, *(_components.at(1).get()))}, // Clock
                {3, std::pair<std::size_t, nts::IComponent&>(1, *(_components.at(5).get()))}, // Set
                {4, std::pair<std::size_t, nts::IComponent&>(1, *(_components.at(6).get()))}  // Reset
                };
    _components.at(2).get()->setLink(2, _components.at(0), 2);
    _components.at(3).get()->setLink(1, _components.at(1), 3);
    _components.at(4).get()->setLink(1, _components.at(2), 3);
    _components.at(5).get()->setLink(2, _components.at(3), 2);
    _components.at(6).get()->setLink(2, _components.at(4), 2);
    _components.at(7).get()->setLink(1, _components.at(5), 3);
    _components.at(7).get()->setLink(2, _components.at(6), 3);
}

nts::FlipFlopComponent::~FlipFlopComponent()
{

}

nts::Tristate nts::FlipFlopComponent::compute(std::size_t pin)
{
    if (pin == 5)
        return _outputs.at(pin).compute(3);
    else if (pin == 6)
        return _outputs.at(pin).compute(4);
    else
        throw std::invalid_argument("Pin out of range");
}

void nts::FlipFlopComponent::simulate(std::size_t tick)
{
    if (_updated == true)
        return;
    _updated = true;
    for (auto &component : _components) {
        component.get()->simulate(tick);
    }
}

void nts::FlipFlopComponent::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin)
{
    if (pin == 1) {
        _components.at(0)->setLink(1, other, otherPin);
        _components.at(1)->setLink(1, other, otherPin);
    } else if (pin == 2) {
        _components.at(1)->setLink(2, other, otherPin);
        _components.at(2)->setLink(1, other, otherPin);
    } else if (pin == 3) {
        _components.at(5)->setLink(1, other, otherPin);
    } else if (pin == 4) {
        _components.at(6)->setLink(1, other, otherPin);
    } else {
        throw std::invalid_argument("Pin out of range");
    }
}

void nts::FlipFlopComponent::resetUpdate(void)
{
    if (_updated == false)
        return;
    _updated = false;
    for (auto &component : _components) {
        component.get()->resetUpdate();
    }
}