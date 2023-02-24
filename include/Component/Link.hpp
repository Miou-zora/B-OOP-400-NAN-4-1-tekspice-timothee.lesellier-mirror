/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Link
*/

#pragma once

#include "IComponent.hpp"
#include <memory>

namespace nts
{
    class Link {
        public:
            Link(nts::IComponent &component, size_t otherPin) : _component(component), _otherPin(otherPin) {};
            ~Link() {};

            size_t getOtherPin() const { return (_otherPin); };

            nts::IComponent &getComponent() const { return (_component); };

        private:
            nts::IComponent &_component;
            size_t _otherPin;
    };
}
