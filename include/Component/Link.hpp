/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Link
*/

#ifndef LINK_HPP_
#define LINK_HPP_

#include "IComponent.hpp"
#include <memory>

namespace nts {
    class Link {
        public:
            Link() : _component(std::shared_ptr<nts::IComponent>(nullptr)) {};
            ~Link() {};

            void setComponent(std::shared_ptr<nts::IComponent> other) { _component = other; };
            void setPin(size_t pin) { _pin = pin; };
            void setOtherPin(size_t otherPin) { _otherPin = otherPin; };

            nts::IComponent &getComponent() const { return (*_component.get()); };
            size_t getPin() const { return (_pin); };
            size_t getOtherPin() const { return (_otherPin); };
        private:
            std::shared_ptr<nts::IComponent> _component;
            size_t _pin;
            size_t _otherPin;
    };
}
#endif /* !LINK_HPP_ */
