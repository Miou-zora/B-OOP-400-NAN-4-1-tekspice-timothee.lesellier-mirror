/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4001
*/

#include "Component/Chip/Component4001.hpp"

nts::Component4001::Component4001()
{
    _pinMax= 13;
    _norComponent = {
                        std::make_shared<nts::NorComponent>(),
                        std::make_shared<nts::NorComponent>(),
                        std::make_shared<nts::NorComponent>(),
                        std::make_shared<nts::NorComponent>()
                    };

    _outputs = {
                {3, *(_norComponent.at(0).get())},
                {4, *(_norComponent.at(1).get())},
                {10, *(_norComponent.at(2).get())},
                {11, *(_norComponent.at(3).get())}
                };

    _inputs = {
                {1, std::pair<std::size_t, nts::IComponent&>(1, *(_norComponent.at(0).get()))},
                {2, std::pair<std::size_t, nts::IComponent&>(2, *(_norComponent.at(0).get()))},
                {5, std::pair<std::size_t, nts::IComponent&>(1, *(_norComponent.at(1).get()))},
                {6, std::pair<std::size_t, nts::IComponent&>(2, *(_norComponent.at(1).get()))},
                {8, std::pair<std::size_t, nts::IComponent&>(1, *(_norComponent.at(2).get()))},
                {9, std::pair<std::size_t, nts::IComponent&>(2, *(_norComponent.at(2).get()))},
                {12, std::pair<std::size_t, nts::IComponent&>(1, *(_norComponent.at(3).get()))},
                {13, std::pair<std::size_t, nts::IComponent&>(2, *(_norComponent.at(3).get()))},
                };
}

nts::Component4001::~Component4001()
{
}

nts::Tristate nts::Component4001::compute(std::size_t pin)
{
    try {
        return _outputs.at(pin).compute(3);
    } catch (std::out_of_range &e) {
        throw std::invalid_argument("Pin out of range");
    }
}

void nts::Component4001::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin)
{
    try {
        _inputs.at(pin).second.setLink(_inputs.at(pin).first, other, otherPin);
    } catch (std::out_of_range &e) {
        throw std::invalid_argument("Pin out of range");
    }
}


