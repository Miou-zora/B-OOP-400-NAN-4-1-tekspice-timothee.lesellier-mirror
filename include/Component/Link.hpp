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
            Link() : _component(std::shared_ptr<nts::IComponent>(nullptr)) {};
            ~Link() {};

            void setPin(size_t pin) { _pin = pin; };
            size_t getPin() const { return (_pin); };

            void setOtherPin(size_t otherPin) { _otherPin = otherPin; };
            size_t getOtherPin() const { return (_otherPin); };

            void setComponent(std::shared_ptr<nts::IComponent> other) { _component = other; };
            std::shared_ptr<nts::IComponent> getComponent() const { return (_component); };

        private:
            std::shared_ptr<nts::IComponent> _component;
            size_t _pin;
            size_t _otherPin;
    };
}
