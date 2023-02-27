/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** InvSRNLatchComponent
*/

#include "Component/Chip/InvSRNLatchComponent.hpp"
#include "Component/Chip/NotComponent.hpp"
#include "Component/Chip/SRLatchComponent.hpp"

nts::InvSRNLatchComponent::InvSRNLatchComponent()
{
    _pinMax = 4;
    _components = {
                    std::make_shared<nts::NotComponent>(), // In 1
                    std::make_shared<nts::NotComponent>(), // In 2
                    std::make_shared<nts::NotComponent>(), // Out 1
                    std::make_shared<nts::NotComponent>(), // Out 2
                    std::make_unique<nts::SRLatchComponent>() // SR Latch
                };
    _outputs = {
                {3, *(_components.at(2).get())},
                {4, *(_components.at(3).get())}
                };

    _inputs = {
                {1, std::pair<std::size_t, nts::IComponent&>(1, *(_components.at(0).get()))},
                {2, std::pair<std::size_t, nts::IComponent&>(1, *(_components.at(1).get()))}
                };
    _components.at(4).get()->setLink(1, _components.at(0), 2); // In 1:2 <- SRL:1
    _components.at(4).get()->setLink(2, _components.at(1), 2); // In 2:2 <- SRL:2
    _components.at(2).get()->setLink(2, _components.at(4), 3); // SRL:3 <- Out 1:2
    _components.at(3).get()->setLink(2, _components.at(4), 4); // SRL:4 <- Out 2:2
}

nts::InvSRNLatchComponent::~InvSRNLatchComponent()
{
}

nts::Tristate nts::InvSRNLatchComponent::compute(std::size_t pin)
{
    try {
        return _outputs.at(pin).compute(2);
    } catch (std::out_of_range &e) {
        throw std::invalid_argument("Pin out of range");
    }
}

void nts::InvSRNLatchComponent::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin)
{
    try {
        _inputs.at(pin).second.setLink(_inputs.at(pin).first, other, otherPin);
    } catch (std::out_of_range &e) {
        throw std::invalid_argument("Pin out of range");
    }
}

void nts::InvSRNLatchComponent::simulate(std::size_t tick)
{
    // _components.at(4).get()->simulate(tick);
}