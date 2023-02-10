/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Link
*/

#ifndef LINK_HPP_
#define LINK_HPP_

#include "IComponent.hpp"

namespace nts {
    class Link {
        public:
            Link() {component = nullptr; otherPin = 0;};
            ~Link() {};

            void setComponent(IComponent *component);
            void setPin(size_t pin);
            void setOtherPin(size_t otherPin);

            IComponent *getComponent() const;
            size_t getPin() const;
            size_t getOtherPin() const;
        private:
            IComponent *component;
            size_t pin;
            size_t otherPin;
    };
}
#endif /* !LINK_HPP_ */
